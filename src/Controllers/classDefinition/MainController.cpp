// MainController.cpp
#include "../classDeclaration/MainController.h"

MainController::MainController(int argc, char *argv[])
    : mainView(argc, argv)
{
    std::cout << "MainController initialized : " << std::endl;
}

void MainController::startMainView()
{
    mainView.start();
}
