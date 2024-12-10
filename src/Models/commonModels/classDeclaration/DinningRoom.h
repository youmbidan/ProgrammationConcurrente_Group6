//
// Created by franck on 12/2/24.
//

#ifndef DINNINGROOM_H
#define DINNINGROOM_H

#include <vector>
#include <queue>

#include "ClientGroupModel.h"
#include "../../dinningRoomModels/classDeclaration/Table.h"

using namespace std;

/**
 * @class DinningRoom
 *
 * @brief this class manage all the elements in the dinning room
 */
class DinningRoom : public Observable {
public:

    DinningRoom();


    /**
     * @brief this function take the list of table which don't have any client
     * on and send it to the Butler
     */
    vector<Table> getFreeTableList();

    ClientGroupModel* getClientGroupFormed();

    ClientGroupModel* getClientGroupAssigned();

    void setClientGroupFormed(ClientGroupModel* clientGroup);

    void setClientGroupAssigned(ClientGroupModel* clientGroup);

private:
    // int breadCartAvailable;
    // int cardDistribueted;
    // int currentClientNumber;
    // int totalClientOfTheDay;
    // bool isFirstSquareBusy;
    // bool isSecondSquareBusy;
    // int firtSquareBusyServerNumber;
    // int secondSquareBusyServerNumber;
    // queue<Table> firstSquareRequest;
    // queue<Table> secondSquareRequest;
    // queue de groupes de clients formés
    queue<ClientGroupModel*> clientGroupsFormed;

    //queue de groupes assignés à une table
    queue<ClientGroupModel*> clientGroupsAssigned;

    //Tableau de tables libres de la salle
    vector<Table*> freeTables;

};

#endif //DINNINGROOM_H
