//
// Created by seand on 12/10/2024.
//

#include "../classDeclaration/DinningRoomController.h"

DinningRoomController::~DinningRoomController() = default;

void DinningRoomController::startClientGroupCreation() {
    ThreadPoolManager::enqueue([this]() {
        while (true) {
            {
                std::unique_lock lock(clientGroupFormedMutex);
                clientGroupFormedCond.wait(lock, [this]() { return clientGroupsFormed.empty(); });
                ClientGroupModel* newGroup = clientGroupFactory->createGroup();
                std::cout << "Groupe de clients cree (DinningRoomController::startClientGroupCreation())" << std::endl;
                clientGroupsFormed.emplace(newGroup);
                std::cout << "Groupe de clients ajoute à la file" << std::endl;
                clientGroupFormedCond.notify_one();
            }

            std::this_thread::sleep_for(std::chrono::seconds(3));  // Limiter la fréquence de création des groupes
        }
    });
}

void DinningRoomController::startToWelcomeClientGroups() {
    ThreadPoolManager::enqueue([this]() {
        while (true) {
            ClientGroupModel* newGroup;

            {
                std::unique_lock lock(clientGroupFormedMutex);
                clientGroupFormedCond.wait(lock, [this]() { return !clientGroupsFormed.empty(); });
                newGroup = clientGroupsFormed.front();
                clientGroupsFormed.pop();
            }

            if (!freeTablesList.empty()) {
                Table* newOccupiedTable = characterElementController->butler->assignTable(newGroup->getClientNumber(), freeTablesList);
                if (newOccupiedTable) {
                    std::unique_lock lock(characterControllerMutex);
                    characterElementController->insertClientGroupOnScene(newGroup);
                    std::cout << "Table attribuée : (" << newOccupiedTable->getAbscice() << ", " << newOccupiedTable->getIntercept()
                              << ") de " << newOccupiedTable->getCapacity() << " places pour un groupe de " << newGroup->getClientNumber() << " personnes." << std::endl;

                    freeTablesList.erase(std::remove(freeTablesList.begin(), freeTablesList.end(), newOccupiedTable), freeTablesList.end());

                    {
                        std::unique_lock lock(clientGroupAssignedMutex);
                        clientGroupsAssigned.emplace(Attribution{newGroup, newOccupiedTable});
                        clientGroupAssignedCond.notify_one();
                    }
                } else {
                    std::cout << "AUCUNE TABLE TROUVEE !!" << std::endl;
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Pause pour éviter une surcharge de threads
        }
    });
}


void DinningRoomController::makeHeadWaiterLeadClientsGroup() {
    /**
     * @brief Le maître d'hôtel conduit les groupes de clients à leurs tables attribuées.
     */

    ThreadPoolManager::enqueue([this]() {
            Attribution currentAttribution{};

            {
                std::unique_lock lock(clientGroupAssignedMutex);
                clientGroupAssignedCond.wait(lock, [this]() {
                    return !clientGroupsAssigned.empty();
                });
                currentAttribution = clientGroupsAssigned.front();
                clientGroupsAssigned.pop();
            }

            Table* currentTable = currentAttribution.tableAssociated;

            PointStruct associatedTableCoord = {
                currentTable->getAbscice(),
                currentTable->getIntercept()
            };

            // cout << "Commencons à nous déplacer" << endl
            // cout << "nombre de clients du groupe : " << currentAttribution.clientGroup->getClientNumber() << endl;
            //
            ClientGroupModel* currentClientGroup = currentAttribution.clientGroup;
            currentClientGroup->move(associatedTableCoord);
            cout << "On s'en va vers la table..." << endl;
            {
                std::unique_lock lock(characterControllerMutex);
                characterElementController->headWaiter->move(associatedTableCoord);
            }
            cout << "On revient à la position initiale" << endl;

            currentTable->addClientsToTable(currentClientGroup->getClientGroup());
            {
                std::unique_lock lock(orderingTablesMutex);
                orderingTables.push(currentTable);
                orderingTablesCond.notify_one();
            }
            // Ré-enqueue la tâche après une pause pour ne pas monopoliser un thread
            ThreadPoolManager::enqueue([this]() {
                this->makeHeadWaiterLeadClientsGroup();
            });

            return;
        }
    );
}

void DinningRoomController::startTakingOrders() {
    ThreadPoolManager::enqueue([this]() {
        Table* currentOrderingTable;
        {
            std::unique_lock lock(orderingTablesMutex);
            orderingTablesCond.wait(lock, [this]() { return !orderingTables.empty(); });
            currentOrderingTable = orderingTables.front();
            orderingTables.pop();
        }

        int neededCards = currentOrderingTable->getClientsOnTable().size() > 4 ? 2 : 1;

        std::unique_lock lock(cardMutex);
        if (cardLeft >= neededCards) {
            cardLeft -= neededCards;
            for (ClientModel* client : currentOrderingTable->getClientsOnTable()) {
                client->makeChoice(currentCard->getCurrentCard());
                std::this_thread::sleep_for(std::chrono::seconds(5));  // Délais entre chaque choix
                std::cout << "un client a fait son choix" << std::endl;

                {
                    std::unique_lock lock(orderingTablesMutex);
                    orderingTables.pop();
                }

                {
                    std::unique_lock lock(orderedTablesMutex);
                    orderedTables.push(currentOrderingTable);
                    orderedTablesCond.notify_one();
                }
            }
        } else {
            std::cout << "PAS ASSEZ DE CARTES... RESTEZ EN ATTENTE SVP" << std::endl;
        }

        ThreadPoolManager::enqueue([this]() {
            this->startTakingOrders();  // Re-enqueue pour la prochaine itération
        });
    });
}


void DinningRoomController::startCollectingOrders() {
    ThreadPoolManager::enqueue([this]() {
        Table* currentOrderedTable;

        {
            std::unique_lock lock(orderedTablesMutex);
            orderedTablesCond.wait(lock, [this]() { return !orderedTables.empty(); });
            currentOrderedTable = orderedTables.front();
            orderedTables.pop();
        }

        vector<Recipe*> tableChoices;
        for (ClientModel* client : currentOrderedTable->getClientsOnTable()) {
            tableChoices.push_back(client->getChoice());
        }

        std::unordered_map<Recipe*, int> recipeCounts;

        for (Recipe* recipe : tableChoices) {
            recipeCounts[recipe]++;
        }

        std::vector<OrderRecipe*> orderRecipes;
        for (const auto& [recipe, quantity] : recipeCounts) {
            orderRecipes.emplace_back(new OrderRecipe{recipe, quantity});
        }

        Order* newOrder = new Order(orderRecipes, currentOrderedTable->getTableId());
        std::cout << "APPORTONS LES COMMANDES DE LA TABLE " << currentOrderedTable->getTableId() << " AU COMPTOIR" << std::endl;

        int neededCards = currentOrderedTable->getClientsOnTable().size() > 4 ? 2 : 1;
        cardLeft += neededCards;

        {
            std::unique_lock lock(characterControllerMutex);
            characterElementController->second_headWaiter->move({currentOrderedTable->getAbscice(), currentOrderedTable->getIntercept()});
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            characterElementController->second_headWaiter->move({1000, 100});
        }

        sharedOrdersQueue.addOrder(*newOrder);

        {
            std::unique_lock lock(readyOrdersMutex);
            readyOrders.push(*newOrder);
            readyOrdersCond.notify_one();
        }

        ThreadPoolManager::enqueue([this]() {
            this->startCollectingOrders();
        });
    });
}

void DinningRoomController::setFreeTablesList() {
    freeTablesList = TableFactory::dinningRoomTables;
}

void DinningRoomController::setAllTablesList() {
    allTablesList = TableFactory::dinningRoomTables;
}

void DinningRoomController::addOrder(const Order& order) {
    std::cout << "DinningRoomController: Nouvelle commande ajoutée pour la table : " << order.getTableId() << std::endl;
        sharedOrdersQueue.addOrder(order);
}

// void DinningRoomController::handleOrderCompletion(Order *order) {
//
// }

void DinningRoomController::startServeClients() {
    // Lancer le travail de service des clients dans un thread du pool
    ThreadPoolManager::enqueue([this]() {
        while (true) {
            // Attendre jusqu'à ce qu'il y ait des commandes prêtes à être servies
            std::unique_lock lock(readyOrdersMutex);
            readyOrdersCond.wait(lock, [this]() { return !readyOrders.empty(); });

            // Récupérer la première commande prête
            Order currentOrder = readyOrders.front();
            Table* tableAssociate = findTableById(currentOrder.getTableId());

            characterElementController->server->move({1000, 100});
            std::this_thread::sleep_for(std::chrono::milliseconds(300)); // Exemple de pause

            // Déplacer le serveur vers la table associée
            characterElementController->server->move({tableAssociate->getAbscice(), tableAssociate->getIntercept()});

            // Une fois le serveur arrivé à la table, retirer la commande de la file
            readyOrders.pop();

            // Vous pouvez ajouter des logs ou d'autres actions ici si nécessaire
            std::cout << "Commande servie pour la table " << currentOrder.getTableId() << std::endl;

            // Pause pour ne pas surcharger le thread pool
            std::this_thread::sleep_for(std::chrono::milliseconds(300)); // Exemple de pause
        }
    });
}


Table* DinningRoomController::findTableById(int id) {
    vector<Table*> alt = allTablesList; // Copie pour ne pas modifier la liste d'origine
    for (const auto& table : alt) {
        if (table->getTableId() == id) {
            return table;
        }
    }
    return nullptr;
}












