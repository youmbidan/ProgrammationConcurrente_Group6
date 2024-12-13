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
    KitchenController kitchenController(new ChiefModel());
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
    //m_mainView.updateConfiguration(time, clients, mode, additionalInfo); // Mise à jour de la vue principale avec les informations
    motionlessElementController->createAllTable();
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



