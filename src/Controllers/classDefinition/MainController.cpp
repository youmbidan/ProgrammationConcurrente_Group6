#include "../classDeclaration/MainController.h"

MainController::MainController(MainView &mainView, MobilePointView &mobile_point)
    : mainView(mainView), mobile_point(mobile_point)
{
    // Création dynamique d'un MobilePointModel
    mobile_point_model = new MobilePointModel(mobile_point.getX(), mobile_point.getY());
    mobile_point_model->subscribe(&mobile_point);    // Ajouter MobilePoint comme observateur
    std::cout << "MainController initialized." << std::endl;

    // Connecter le signal de MobilePoint au slot de MainView
    // QObject::connect(&mobile_point, &MobilePoint::positionUpdated, &mainView, &MainView::onPositionUpdated);
}


void MainController::startMainView()
{
    mainView.start();
    std::cout << "start moving..." << std::endl;
    mobile_point_model->move();
}
