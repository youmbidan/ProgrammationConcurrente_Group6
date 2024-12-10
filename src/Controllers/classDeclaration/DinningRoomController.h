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
#include "../../Models/commonModels/classDeclaration/ClientGroupModel.h"
#include "../../Models/dinningRoomModels/classDeclaration/Table.h"
#include "../../Utilities/ThreadPoolManager.h"


class DinningRoomController {
    // queue de groupes de clients formés
    queue<ClientGroupModel*> clientGroupsFormed;

    //queue de groupes assignés à une table
    queue<ClientGroupModel*> clientGroupsAssigned;

    //Tableau de tables libres de la salle
    vector<Table*> freeTablesList;

    //pour pouvoir récupérer les instances des personnages
    CharacterElementController *characterElementController;

    ClientGroupFactory *clientGroupFactory;

    MotionlessElementController *motionlessElementController;

    ThreadPoolManager *threadPoolManager;

    std::mutex clientGroupFormedMutex;

    std::condition_variable clientGroupformedCond;



    public:
    /**
     *
     * @param characterElementController
     * @param motionlessElementController
     * @param threadPoolManager
     */
    DinningRoomController(
        CharacterElementController *characterElementController, MotionlessElementController *motionlessElementController
        )
        : characterElementController(characterElementController),
            clientGroupFactory(new ClientGroupFactory()),
            motionlessElementController(motionlessElementController)
    {};

    ~DinningRoomController();

    void startClientGroupCreation();

    void startToWelcomeClientGroups();

};



#endif //DINNINGROOMCONTROLLER_H
