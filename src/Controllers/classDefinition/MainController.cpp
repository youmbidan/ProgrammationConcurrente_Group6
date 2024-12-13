#include "../classDeclaration/MainController.h"
#include "../../Views/SetupView/SetupView.h"
#include "../../Views/MainView.h"

MainController::MainController(MainView &mainView)
    : mainView(&mainView), sharedOrdersQueue()
{
    dinningRoomView = mainView.getDinningRoomView();
    kitchenView = mainView.getKitchenView();
    motionlessElementController = new MotionlessElementController(dinningRoomView);
    characterElementController = new CharacterElementController(&mainView);
    threadPoolManager = new ThreadPoolManager();
    dinningRoomController = new DinningRoomController( sharedOrdersQueue,characterElementController, motionlessElementController);
    KitchenController kitchenController(new ChiefModel(), sharedOrdersQueue);
}


void MainController::startMainView() {
    SetupView* setupView = new SetupView();

    // Connexion du signal de validation de la configuration au slot
    connect(setupView, &SetupView::configurationValidated, this, &MainController::onConfigurationValidated);

    setupView->show(); // Affiche la vue de configuration
}

void MainController::onConfigurationValidated(int time, int clients, const QString& mode, const QString& additionalInfo) {
    // Une fois la configuration validée, afficher la vue principale
    mainView->show();
    motionlessElementController->createAllTable();
    // kitchenController->processOrders();
    dinningRoomController->setFreeTablesList();
    characterElementController->initializeEmployeesCharacter();
    dinningRoomController->startClientGroupCreation();
    dinningRoomController->startToWelcomeClientGroups();
    dinningRoomController->makeHeadWaiterLeadClientsGroup();
    dinningRoomController->startTakingOrders();
    dinningRoomController->startCollectingOrders();
}

// void MainController::connectControllers() {

    // lors de l'envoi d'une commande
    // connect(dinningRoomController, &DinningRoomController::newOrderReady,
    //         kitchenController, &KitchenController::receiveOrder);

    // commande prête
    // connect(kitchenController, &KitchenController::orderCompleted,
    //             dinningRoomController, &DinningRoomController::handleOrderCompletion);
// }



