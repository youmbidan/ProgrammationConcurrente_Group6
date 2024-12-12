#include "src/Controllers/classDeclaration/MainController.h"
#include "src/Views/SetupView/SetupView.h"
#include "src/Views/MainView.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Créer la vue de configuration (SetupView)
    SetupView setupView;

    // Connecter le signal de SetupView pour démarrer MainView avec les paramètres
    QObject::connect(&setupView, &SetupView::configurationValidated, [&](int time, int clients, const QString& mode, const QString& additionalInfo) {
        // Créer MainView et le contrôleur principal
        MainView* mainView = new MainView(time, clients, mode, additionalInfo);
        MainController mainController(*mainView);

        // Lancer la vue principale
        mainController.startMainView();

        // Supprimer SetupView après avoir affiché MainView
        setupView.close();
        mainView->show();
    });

    // Afficher SetupView pour commencer
    setupView.show();

    return QApplication::exec();
}
