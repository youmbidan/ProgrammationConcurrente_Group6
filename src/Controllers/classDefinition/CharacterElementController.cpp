//
// Created by seand on 12/5/2024.
//

#include "../classDeclaration/MobileElementController.h"


MobileElementController::MobileElementController(MainView main_view) {

    vector<int> priority_table {2, 4, 5, 10};


    //instanciation des objets
    this->butler = new Butler(0, priority_table );
    this->headWaiter = new HeadWaiter();
    this->server = new Server();

    //On déclare les éléments graphiques associés
    this->butler_point_view = new MobilePointView(20, 20);
    this->head_waiter_point_view = new MobilePointView(20, 20);
    this->second_head_waiter_point_view = new MobilePointView(20, 20);
    this->server_point_view = new MobilePointView(20, 20);
    this->second_server_point_view = new MobilePointView(20, 20);
};

