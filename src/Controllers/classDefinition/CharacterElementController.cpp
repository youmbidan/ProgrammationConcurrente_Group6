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
    butler_point_view = new CommonPointView("butler", 20, 20, "/assets/maitrehotel.png", nullptr);
    head_waiter_point_view = new CommonPointView("headWaiter", 100, 100,"/assets/maitrehotel.png", nullptr);
    second_head_waiter_point_view = new CommonPointView("headWaiter2", 120, 120, "/assets/maitrehotel.png", nullptr);
    server_point_view = new CommonPointView("server", 20, 500,"/assets/serveur1.png", nullptr);
    second_server_point_view = new CommonPointView("server2", 100, 500, "/assets/serveur1.png",nullptr);
    room_clerk_point_view = new CommonPointView("roomClerk", 500, 500, "/assets/commis.png", nullptr);

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
    // Récupérer le nombre de clients et définir un label descriptif
    const int nbr_client = clientGroup->getClientNumber();
    const std::string clientLabel = "Clients(" + std::to_string(nbr_client) + ")";

    // Créer un point graphique représentant le groupe de clients
    CommonPointView* client_point_view = new CommonPointView(QString::fromStdString(clientLabel), 0, 20,"/assets/group4.png", nullptr);

    // Synchroniser les coordonnées entre le modèle et la vue
    PointStruct clientGroupCoord = {
        static_cast<double>(client_point_view->getX()),
        static_cast<double>(client_point_view->getY())
    };
    clientGroup->setCoords(clientGroupCoord);

    // Inscrire la vue comme observateur du modèle
    clientGroup->subscribe(client_point_view);
    std::cout << "Point graphique du client inscrit a son modele" << std::endl;

    // Ajouter le groupe de clients à la scène de la salle à manger
    QMetaObject::invokeMethod(dinningRoomView, [client_point_view, this]() {
        dinningRoomView->addClientsToScene(client_point_view);
    }, Qt::QueuedConnection);
    // dinningRoomView->addClientsToScene(client_point_view);
    std::cout << "Nouveau groupe de clients ajouté a la scene" << std::endl;

    clientPointViews.push_back(client_point_view);

    cout << "taille du tableau de points : " << clientPointViews.size() << endl;

}





