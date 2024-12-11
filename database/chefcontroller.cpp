#include "ChefController.h"
#include "Recipe.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

ChefController::ChefController(ChefModel* chefModel)
    : chefModel(chefModel), nextOrderId(1) {
    // Initialiser le générateur aléatoire
    std::srand(std::time(nullptr));
}

void ChefController::simulateIncomingOrder() {
    Order order(nextOrderId++, QString("Détails de la commande %1").arg(nextOrderId));

    // Générer aléatoirement entre 1 et 3 recettes
    int numRecipes = std::rand() % 3 + 1;
    for (int i = 0; i < numRecipes; ++i) {
        Recipe recipe(
            static_cast<RecipesNames>(std::rand() % 5),          // Nom aléatoire
            static_cast<RecipesTypes>(std::rand() % 3),          // Type aléatoire
            std::rand() % 15 + 5                               // Temps de cuisson aléatoire ()
            );
        order.recipes.append(recipe);

        // Affichage des détails de la recette
        qDebug() << "Recette créée: Nom =" << static_cast<int>(recipe.name)
                 << ", Type =" << static_cast<int>(recipe.type)
                 << ", Temps de cuisson =" << recipe.cookingTime << "secondes.";

    }

    chefModel->addOrder(order);
    qDebug() << "Commande simulée" << order.id << "avec" << order.recipes.size() << "recettes.";
}

ChefModel* ChefController::getChefModel() const {
    return chefModel;
}
