//
// Created by seand on 12/5/2024.
//

#ifndef MOBILEELEMENTCONTROLLER_H
#define MOBILEELEMENTCONTROLLER_H

#include "../../Models/dinningRoomModels/classDeclaration/Butler.h"
#include "../../Models/dinningRoomModels/classDeclaration/headWaiter.h"
#include "../../Models/dinningRoomModels/classDeclaration/Server.h"
#include "../../Models/dinningRoomModels/classDeclaration/RoomClerk.h"
#include "../../Views/MainView.h"
#include "../../Models/commonModels/classDeclaration/ClientGroupModel.h"

#include <vector>

#include "../../Views/CommonPointView.h"

/**
 * @class CharacterElementController
 *
 * @brief Class for handling mobile element instantiation and some others stuffs
 */

class CharacterElementController {
public:
 /**
  * @brief  constructor, take an instance of MainView as a parameter
  *
  * @param mainview
  */
 explicit CharacterElementController(MainView *mainview);

// made all these attributes static in purpose to access them all over the project
 static Butler *butler;
 static HeadWaiter *headWaiter;
 static HeadWaiter *second_headWaiter;
 static Server *server;
 static Server *second_server;
 static RoomClerk *roomClerk;

 static ClientGroupModel *clientGroup;

 static CommonPointView *butler_point_view;
 static CommonPointView *head_waiter_point_view;
 static CommonPointView *second_head_waiter_point_view;
 static CommonPointView *server_point_view;
 static CommonPointView *second_server_point_view;
 static CommonPointView *room_clerk_point_view;

 CommonPointView *client_group_point_view;

 private:
 MainView main_view;

 /**
  * @brief initialize employees/clients and associate them with
  * corresponding models.
  * Also add them to scene
  */
 void initializeEmployeesCharacter();
 void initializeClientsCharacter();


};



#endif //MOBILEELEMENTCONTROLLER_H
