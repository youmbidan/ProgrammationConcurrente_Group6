//
// Created by seand on 12/5/2024.
//

#include "../classDeclaration/CharacterElementController.h"

CharacterElementController::CharacterElementController(MainView *mainview): main_view(mainview) {
    kitchenView = mainview->getKitchenView();
    dinningRoomView = mainview->getDinningRoomView();

};

void CharacterElementController::initializeEmployeesCharacter() {

    // Création des éléments graphiques
    butler_point_view = new CommonPointView("butler", 20, 20, nullptr);
    head_waiter_point_view = new CommonPointView("headWaiter", 100, 100, nullptr);
    second_head_waiter_point_view = new CommonPointView("headWaiter2", 120, 120, nullptr);
    server_point_view = new CommonPointView("server", 20, 500, nullptr);
    second_server_point_view = new CommonPointView("server2", 100, 500, nullptr);
    room_clerk_point_view = new CommonPointView("roomClerk", 500, 500, nullptr);

    // Instanciation des objets
    butler = new Butler();
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

void CharacterElementController::insertClientGroupOnScene(ClientGroupModel* clientGroup) {
    const int nbr_client = clientGroup->getClientNumber();
    const std::string clientLabel = "Clients(" + std::to_string(nbr_client) + ")";
    client_point_view =  new CommonPointView(clientLabel.data(), 10, 20, nullptr, nbr_client );
    dinningRoomView->addClientsToScene(client_point_view);
    cout << "point cree, notifions la vue" << endl;

}





