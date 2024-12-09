//
// Created by seand on 12/5/2024.
//

#include "../classDeclaration/CharacterElementController.h"


#include "../classDeclaration/CharacterElementController.h"

// Initialisation des membres statiques
Butler* CharacterElementController::butler = nullptr;
HeadWaiter* CharacterElementController::headWaiter = nullptr;
HeadWaiter* CharacterElementController::second_headWaiter = nullptr;
Server* CharacterElementController::server = nullptr;
Server* CharacterElementController::second_server = nullptr;
RoomClerk* CharacterElementController::roomClerk = nullptr;

ClientGroupModel* CharacterElementController::clientGroup = nullptr;

CommonPointView* CharacterElementController::butler_point_view = nullptr;
CommonPointView* CharacterElementController::head_waiter_point_view = nullptr;
CommonPointView* CharacterElementController::second_head_waiter_point_view = nullptr;
CommonPointView* CharacterElementController::server_point_view = nullptr;
CommonPointView* CharacterElementController::second_server_point_view = nullptr;
CommonPointView* CharacterElementController::room_clerk_point_view = nullptr;


CharacterElementController::CharacterElementController(MainView *mainview): main_view(mainview) {
    kitchenView = mainview->getKitchenView();
    dinningRoomView = mainview->getDinningRoomView();

};

void CharacterElementController::initializeEmployeesCharacter() {
    const vector<int> priority_table{2, 4, 6, 8, 10};

    // Création des éléments graphiques
    butler_point_view = new CommonPointView("butler", 20, 20, nullptr);
    head_waiter_point_view = new CommonPointView("headWaiter", 100, 100, nullptr);
    second_head_waiter_point_view = new CommonPointView("headWaiter2", 120, 120, nullptr);
    server_point_view = new CommonPointView("server", 20, 500, nullptr);
    second_server_point_view = new CommonPointView("server2", 100, 500, nullptr);
    room_clerk_point_view = new CommonPointView("roomClerk", 500, 500, nullptr);

    // Instanciation des objets
    butler = new Butler(0, priority_table);
    headWaiter = new HeadWaiter(head_waiter_point_view->getX(), head_waiter_point_view->getY());
    second_headWaiter = new HeadWaiter(second_head_waiter_point_view->getX(), second_head_waiter_point_view->getY());
    server = new Server(server_point_view->getX(), server_point_view->getY(), 1, 5);
    second_server = new Server(second_server_point_view->getX(), second_server_point_view->getY(), 1, 5);
    roomClerk = new RoomClerk(room_clerk_point_view->getX(), room_clerk_point_view->getY(), 1, 5);

    // Association des modèles aux vues graphiques
    headWaiter->subscribe(head_waiter_point_view);
    second_headWaiter->subscribe(second_head_waiter_point_view);
    server->subscribe(server_point_view);
    second_server->subscribe(second_server_point_view);
    roomClerk->subscribe(room_clerk_point_view);

    //add them to scene
    dinningRoomView->addCharacterToScene(butler_point_view);
    dinningRoomView->addCharacterToScene(head_waiter_point_view);
    dinningRoomView->addCharacterToScene(second_head_waiter_point_view);
    dinningRoomView->addCharacterToScene(server_point_view);
    dinningRoomView->addCharacterToScene(second_server_point_view);
    dinningRoomView->addCharacterToScene(room_clerk_point_view);

}


void CharacterElementController::initializeClientsCharacter() {
    // this->client_group_point_view = new CommonPointView("client_group",20, 20);

}





