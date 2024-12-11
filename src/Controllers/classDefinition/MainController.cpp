#include "../classDeclaration/MainController.h"
#include "../../Views/SetupView/SetupView.h"
#include "../../Views/MainView.h"

MainController::MainController(MainView& mainView)
    : m_mainView(mainView) {}

void MainController::startMainView() {
    SetupView* setupView = new SetupView();

    // Connexion du signal de validation de la configuration au slot
    connect(setupView, &SetupView::configurationValidated, this, &MainController::onConfigurationValidated);
    
    setupView->show(); // Affiche la vue de configuration
}

void MainController::onConfigurationValidated(int time, int clients, const QString& mode, const QString& additionalInfo) {
    // Une fois la configuration validée, afficher la vue principale
    m_mainView.show();
    //m_mainView.updateConfiguration(time, clients, mode, additionalInfo); // Mise à jour de la vue principale avec les informations
}
