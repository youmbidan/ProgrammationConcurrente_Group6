//
// Created by seand on 12/5/2024.
//

#include "../classDeclaration/CharacterElementController.h"


CharacterElementController::CharacterElementController(MainView *mainview): main_view(mainview) {
    initializeEmployeesCharacter();

};

void CharacterElementController::initializeEmployeesCharacter() {
    const vector priority_table {2, 4, 6, 8, 10};

    //Graphic elements creation
    this->butler_point_view = new CommonPointView("butler",20, 20);
    this->head_waiter_point_view = new CommonPointView("headWaiter",20, 20);
    this->second_head_waiter_point_view = new CommonPointView("headWaiter2",20, 20);
    this->server_point_view = new CommonPointView("server",20, 20);
    this->second_server_point_view = new CommonPointView("server2",20, 20);
    this->room_clerk_point_view = new CommonPointView("roomClerk",20, 20);

    //Objects instantiation
    butler = new Butler(0, priority_table );
    headWaiter = new HeadWaiter(head_waiter_point_view->getX(),head_waiter_point_view->getY());
    second_headWaiter = new HeadWaiter(second_head_waiter_point_view->getX(),second_head_waiter_point_view->getY());
    server = new Server(server_point_view->getX(),server_point_view->getY(),1,5);
    second_server = new Server(second_server_point_view->getX(),second_server_point_view->getY(),1,5);
    roomClerk = new RoomClerk(room_clerk_point_view->getX(),room_clerk_point_view->getY(),1,5);

    //Attach ours graphics element to ours models instances
    headWaiter->subscribe(this->head_waiter_point_view);
    second_headWaiter->subscribe(this->second_head_waiter_point_view);
    server->subscribe(this->server_point_view);
    second_server->subscribe(this->second_server_point_view);
    roomClerk->subscribe(this->room_clerk_point_view);
}

void CharacterElementController::initializeClientsCharacter() {
    this->client_group_point_view = new CommonPointView("client_group",20, 20);

}





