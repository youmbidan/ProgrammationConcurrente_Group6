#include "../classDeclaration/MainController.h"

MainController::MainController(MainView &mainView)
    : mainView(&mainView)
{

}


void MainController::startMainView()
{
    mainView->start();
}

