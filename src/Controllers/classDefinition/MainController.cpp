#include "../classDeclaration/MainController.h"

MainController::MainController(MainView &mainView)
    : mainView(&mainView)
{
    dinningRoomView = mainView.getDinningRoomView();
    motionlessElementController = new MotionlessElementController(dinningRoomView);
    characterElementController = new CharacterElementController(&mainView);
    threadPoolManager = new ThreadPoolManager();
    dinningRoomController = new DinningRoomController(characterElementController, motionlessElementController);
}


void MainController::startMainView()
{
    mainView->start();
    motionlessElementController->createAllTable();
    characterElementController->initializeEmployeesCharacter();
    dinningRoomController->startClientGroupCreation();
    dinningRoomController->startToWelcomeClientGroups();
}

