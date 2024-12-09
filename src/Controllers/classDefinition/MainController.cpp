#include "../classDeclaration/MainController.h"

MainController::MainController(MainView &mainView)
    : mainView(&mainView)
{
    dinningRoomView = mainView.getDinningRoomView();
    motionlessElementController = new MotionlessElementController(dinningRoomView);
    characterElementController = new CharacterElementController(&mainView);
}


void MainController::startMainView()
{
    mainView->start();
    motionlessElementController->createAllTable();
    characterElementController->initializeEmployeesCharacter();
}

