//
// Created by seand on 12/10/2024.
//

#ifndef DINNINGROOMCONTROLLER_H
#define DINNINGROOMCONTROLLER_H
#include <queue>
#include <mutex>
#include <condition_variable>

#include "CharacterElementController.h"
#include "MotionlessElementController.h"
#include "../../Factories/classDeclaration/ClientGroupFactory.h"
#include "../../Models/commonModels/classDeclaration/CardModel.h"
#include "../../Models/commonModels/classDeclaration/ClientGroupModel.h"
#include "../../Models/dinningRoomModels/classDeclaration/Table.h"
#include "../../Utilities/ThreadPoolManager.h"
#include "../../Structs/Attribution.h"
#include "../../Factories/classDeclaration/TableFactory.h"
#include "../classDeclaration/SharedOrdersQueue.h"



class DinningRoomController {
    // queue de groupes de clients formés
    queue<ClientGroupModel*> clientGroupsFormed;

    //queue de groupes assignés à une table
    queue<Attribution> clientGroupsAssigned;

    //Tableau de tables libres de la salle
    vector<Table*> freeTablesList;

    //Tableau de tables libres de la salle
    vector<Table*> allTablesList;

    // Nombre de cartes de restaurant disponibles
    int cardLeft = 40;

    // queue de groupe de clients installés sans avoir passé commande
    queue<Table*> orderingTables;

    // queue de tables ayant déjà commandée
    queue<Table*> orderedTables;

    queue<Order> readyOrders;

    std::mutex readyOrdersMutex;

    std::condition_variable readyOrdersCond;

    //pour pouvoir récupérer les instances des personnages
    CharacterElementController *characterElementController;

    ClientGroupFactory *clientGroupFactory;

    MotionlessElementController *motionlessElementController;

    ThreadPoolManager *threadPoolManager;

    std::mutex clientGroupFormedMutex;

    std::condition_variable clientGroupFormedCond;

    std::mutex clientGroupAssignedMutex;

    std::condition_variable clientGroupAssignedCond;

    std::mutex orderingTablesMutex;

    std::condition_variable orderingTablesCond;

    std::mutex orderedTablesMutex;

    std::condition_variable orderedTablesCond;

    CardModel *currentCard;

    std::mutex cardMutex;

    std::mutex characterControllerMutex;

    std::condition_variable characterControllerCond;

    std::queue<Order*> ordersOnCounterQueue;

    std::queue<Order*> ordersReadyOnCounterQueue;

    SharedOrdersQueue& sharedOrdersQueue;

    public:
    /**
     *
     * @param characterElementController
     * @param motionlessElementController
     */
    DinningRoomController(SharedOrdersQueue& sharedOrdersQueue,
        CharacterElementController *characterElementController, MotionlessElementController *motionlessElementController
        )
        : characterElementController(characterElementController),
            clientGroupFactory(new ClientGroupFactory()),
            motionlessElementController(motionlessElementController),
            sharedOrdersQueue(sharedOrdersQueue),
            currentCard(new CardModel()) {};

    ~DinningRoomController();

    void setFreeTablesList();

    void setAllTablesList();

    void startClientGroupCreation();

    void startToWelcomeClientGroups();

    void makeHeadWaiterLeadClientsGroup();

    void startTakingOrders();

    void startCollectingOrders();

    void startServeClients();

    void addOrder(const Order& order);

    Table* findTableById(int id);

    // public slots:
    //     void handleOrderCompletion(Order* order);

    // signals:
    //     void newOrderReady(Order* order);




};




#endif //DINNINGROOMCONTROLLER_H
