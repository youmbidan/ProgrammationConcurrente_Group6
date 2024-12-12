#include "../classDeclaration/MainController.h"
#include "../../Views/SetupView/SetupView.h"
#include "../../Views/MainView.h"

MainController::MainController(MainView &mainView)
    : mainView(&mainView)
{
    dinningRoomView = mainView.getDinningRoomView();
    kitchenView = mainView.getKitchenView();
    motionlessElementController = new MotionlessElementController(dinningRoomView);
    characterElementController = new CharacterElementController(&mainView);
    threadPoolManager = new ThreadPoolManager();
    dinningRoomController = new DinningRoomController(characterElementController, motionlessElementController);
}


void MainController::startMainView()
{
     SetupView* setupView = new SetupView();

     // Connexion du signal de validation de la configuration au slot
     connect(setupView, &SetupView::configurationValidated, this, &MainController::onConfigurationValidated);

     setupView->show(); // Affiche la vue de configuration
//
}

void MainController::onConfigurationValidated(int time, int clients, const QString& mode, const QString& additionalInfo) {
    // mainView->show();
    motionlessElementController->createAllTable();
    dinningRoomController->setFreeTablesList();
    characterElementController->initializeEmployeesCharacter();
    dinningRoomController->startClientGroupCreation();
    dinningRoomController->startToWelcomeClientGroups();
    dinningRoomController->makeHeadWaiterLeadClientsGroup();
    dinningRoomController->startTakingOrders();
    dinningRoomController->startCollectingOrders();
}

