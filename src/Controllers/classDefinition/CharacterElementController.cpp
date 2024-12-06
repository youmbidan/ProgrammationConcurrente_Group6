//
// Created by seand on 12/5/2024.
//

#include "../classDeclaration/CharacterElementController.h"


CharacterElementController::CharacterElementController(MainView main_view) {

    vector priority_table {2, 4, 6, 8, 10};

    //On déclare les éléments graphiques associés
    this->butler_point_view = new MobilePointView("butler",20, 20);
    this->head_waiter_point_view = new MobilePointView("headWaiter",20, 20);
    this->second_head_waiter_point_view = new MobilePointView("headWaiter2",20, 20);
    this->server_point_view = new MobilePointView("server",20, 20);
    this->second_server_point_view = new MobilePointView("server2",20, 20);
    this->room_clerk_point_view = new MobilePointView("roomClerk",20, 20);

    //instanciation des objets
    this->butler = new Butler(0, priority_table );
    this->headWaiter = new HeadWaiter(head_waiter_point_view->getX(),head_waiter_point_view->getY());
    this->second_headWaiter = new HeadWaiter(second_head_waiter_point_view->getX(),second_head_waiter_point_view->getY());
    this->server = new Server(server_point_view->getX(),server_point_view->getY(),1,5);
    this->second_server = new Server(second_server_point_view->getX(),second_server_point_view->getY(),1,5);
    this->roomClerk = new RoomClerk(room_clerk_point_view->getX(),room_clerk_point_view->getY(),1,5);
};

