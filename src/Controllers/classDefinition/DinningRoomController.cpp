//
// Created by seand on 12/10/2024.
//

#include "../classDeclaration/DinningRoomController.h"

void DinningRoomController::startClientGroupCreation() {
    /**
     * @brief Crée des groupes de clients en boucle et les ajoute à la file à traiter.
     * Cela utilise un thread d'arrière-plan via ThreadPoolManager.
     */

    ThreadPoolManager::enqueue([this]() {
        while (true) {
            {
                std::unique_lock lock(clientGroupFormedMutex);
                clientGroupFormedCond.wait(lock, [this](){return clientGroupsFormed.empty();});
                ClientGroupModel* newGroup = clientGroupFactory->createGroup();
                std::cout << "Groupe de clients cree (DinningRoomController::startClientGroupCreation())" << std::endl;
                clientGroupsFormed.emplace(newGroup);
                std::cout << "Groupe de clients ajoute à la file" << std::endl;
                clientGroupFormedCond.notify_one();
            }

            // Pause pour limiter la fréquence de création des groupes.
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
    });
}

void DinningRoomController::setFreeTablesList() {
    freeTablesList = TableFactory::dinningRoomTables;
}

void DinningRoomController::startToWelcomeClientGroups() {
    ThreadPoolManager::enqueue([this]() {
        while (true) {
            ClientGroupModel* newGroup;

            {
                std::unique_lock lock(clientGroupFormedMutex);
                clientGroupFormedCond.wait(lock, [this]() {
                    return !clientGroupsFormed.empty();
                });
                newGroup = clientGroupsFormed.front();
                clientGroupsFormed.pop();
            }


            if (!freeTablesList.empty()) {
                Table* newOccupiedTable = characterElementController->butler->assignTable(newGroup->getClientNumber(), freeTablesList);
                if(newOccupiedTable) {
                    {
                        std::unique_lock lock(characterControllerMutex);
                        characterElementController->insertClientGroupOnScene(newGroup);
                    }
                    std::cout << "Table attribuée : (" << newOccupiedTable->getAbscice() << ", " << newOccupiedTable->getIntercept()
                              << ") de " << newOccupiedTable->getCapacity() << " places pour un groupe de " << newGroup->getClientNumber() << " personnes." << std::endl;

                    freeTablesList.erase(std::remove(freeTablesList.begin(), freeTablesList.end(), newOccupiedTable), freeTablesList.end());

                    {
                        std::unique_lock lock(clientGroupAssignedMutex);
                        clientGroupsAssigned.emplace(Attribution{newGroup, newOccupiedTable});
                        clientGroupAssignedCond.notify_one();
                    }
                } else {
                    cout << "AUCUNE TABLE TROUVEE !!" << endl;
                }
            }

            // Ré-enqueue la tâche après une pause pour ne pas monopoliser un thread
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            ThreadPoolManager::enqueue([this]() {
                this->startToWelcomeClientGroups();
            });

            return;
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
            QMetaObject::invokeMethod(currentClientGroup, [currentClientGroup, associatedTableCoord]() {
                currentClientGroup->move(associatedTableCoord);
            }, Qt::QueuedConnection);
            cout << "On s'en va vers la table..." << endl;
            {
                std::unique_lock lock(characterControllerMutex);
                characterElementController->headWaiter->move(associatedTableCoord);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                characterElementController->headWaiter->backToInitialPosition();
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
            orderingTablesCond.wait(lock, [this]() {return !orderingTables.empty();});
            currentOrderingTable = orderingTables.front();
        }

        //On détermine combien de cartes la table a besoin
        int neededCards = 1;

        if(currentOrderingTable->getClientsOnTable().size() > 4) {
            neededCards = 2;
        }

        std::unique_lock lock(cardMutex);
        if(cardLeft >= neededCards) {
            cardLeft -= neededCards;
            for(ClientModel* client : currentOrderingTable->getClientsOnTable()) {
                client->makeChoice(currentCard->getCurrentCard());
                std::this_thread::sleep_for(std::chrono::seconds(5));
                cout << "un client a fait son choix" << endl;
                {
                    std::unique_lock lock(orderingTablesMutex);
                    // on l'enleve de la queue des tables qui sont entrain de commander
                    orderingTables.pop();
                }
                {
                    std::unique_lock lock(orderedTablesMutex);
                    // on l'ajoute dans la liste des tables qui on fini de commander
                    orderedTables.push(currentOrderingTable);
                    orderedTablesCond.notify_one();
                }
            }
        } else {
            cout  << "PAS ASSEZ DE CARTES... RESTEZ EN ATTENTE SVP" << endl;
        }


        ThreadPoolManager::enqueue([this]() {
                this->startTakingOrders();
            });
    });
}


void DinningRoomController::startCollectingOrders() {
    ThreadPoolManager::enqueue([this]() {
        Table* currentOrderedTable;

        {
            std::unique_lock lock(orderedTablesMutex);
            orderedTablesCond.wait(lock, [this]() {return !orderedTables.empty();});
            currentOrderedTable = orderedTables.front();
            orderedTables.pop();
        }

        // on constitue l'order pour la table

        vector<Recipe*> tableChoices;
        for(ClientModel* client : currentOrderedTable->getClientsOnTable()) {
            // on récupre les choix de chaque client
            tableChoices.push_back(client->getChoice());
        }

        std::unordered_map<Recipe*, int> recipeCounts;

        // Compte les occurrences de chaque recette
        for (Recipe* recipe : tableChoices) {
            recipeCounts[recipe]++;
        }

        // Crée le vecteur final
        std::vector<OrderRecipe> orderRecipes;
        for (const auto& [recipe, quantity] : recipeCounts) {
            orderRecipes.emplace_back(OrderRecipe{recipe, quantity});
        }


        cout << "APPORTONS LES COMMANDES DE LA TABLE " << currentOrderedTable->getTableId()<< " AU COMPTOIR" << endl;

        {
            std::unique_lock lock(cardMutex);
            int neededCards = 1;

            if(currentOrderedTable->getClientsOnTable().size() > 4) {
                neededCards = 2;
            }
            cardLeft += neededCards;
        }


        // on part déposer les la commande de la table
        {
            std::unique_lock lock(characterControllerMutex);
            characterElementController->second_headWaiter->move({currentOrderedTable->getAbscice(),currentOrderedTable->getIntercept()});
            std::this_thread::sleep_for(std::chrono::seconds(3));
            characterElementController->second_headWaiter->move({1000,100});
        }



        ThreadPoolManager::enqueue([this]() {
            this->startCollectingOrders();
        });
    });
}














