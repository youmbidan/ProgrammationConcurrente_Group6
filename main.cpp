#include "src/Controllers/classDeclaration/MainController.h"
#include <QApplication>
#include "./src/kitchen/ChefModel.h"
#include "./src/kitchen/CookModel.h"
#include "./src/kitchen/ChefController.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Partie 1 : Interface graphique
    MainView mainView(nullptr);
    MainController mainController(mainView);
    mainController.startMainView();

    // Partie 2 : Logique ChefModel et CookModel
    ChefModel chefModel;

    // Ajout de cuisiniers
    CookModel cook1, cook2;
    chefModel.addCook(&cook1);
    chefModel.addCook(&cook2);

    // Initialisation du contrôleur
    ChefController controller(&chefModel);

    // Simuler des commandes
    for (int i = 0; i < 5; ++i) {
        controller.simulateIncomingOrder();
    }

    return QApplication::exec();
}
