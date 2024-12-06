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

#include <vector>

#include "../../Views/MobilePointView.h"

/**
 * @class MobileElementController
 *
 * @brief Class for handling mobile element instantiation and some others stuffs
 */

class MobileElementController {
 public:
 MobileElementController();
 MobileElementController(MainView mainview);
 ~MobileElementController();


 private:
 Butler *butler;
 HeadWaiter *headWaiter;
 HeadWaiter *second_headWaiter;
 Server *server;
 Server *second_server;
 RoomClerk *roomClerk;

 MobilePointView *butler_point_view;
 MobilePointView *head_waiter_point_view;
 MobilePointView *second_head_waiter_point_view;
 MobilePointView *server_point_view;
 MobilePointView *second_server_point_view;
 MobilePointView *room_clerk_point_view;




};



#endif //MOBILEELEMENTCONTROLLER_H
