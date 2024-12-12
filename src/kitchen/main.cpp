#include <QCoreApplication>
#include "ChefModel.h"
#include "CookModel.h"
#include "ChefController.h"

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);

    // Initialisation du modèle
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

    return a.exec();
}
