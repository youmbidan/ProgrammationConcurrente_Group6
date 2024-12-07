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
 explicit CharacterElementController(MainView mainview);


 private:
 Butler *butler;
 HeadWaiter *headWaiter;
 HeadWaiter *second_headWaiter;
 Server *server;
 Server *second_server;
 RoomClerk *roomClerk;

 ClientGroupModel *clientGroup;

 CommonPointView *butler_point_view;
 CommonPointView *head_waiter_point_view;
 CommonPointView *second_head_waiter_point_view;
 CommonPointView *server_point_view;
 CommonPointView *second_server_point_view;
 CommonPointView *room_clerk_point_view;

 CommonPointView *client_group_point_view;

 /**
  * @brief initialize employees/clients and associate them with
  * corresponding models.
  * Also add them to scene
  */
 void initializeEmployeesCharacter();
 void initializeClientsCharacter();




};



#endif //MOBILEELEMENTCONTROLLER_H
