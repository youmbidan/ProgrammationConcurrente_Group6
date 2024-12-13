#include "ChefController.h"
#include "Recipe.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <vector>

// Liste prédéfinie de recettes
const std::vector<Recipe> predefinedRecipes = {
    Recipe(RecipesNames::Pizza, RecipesTypes::Vegetarian, 7,
           {"Tomate", "Farine", "Sel"},
           {UstensilModel("Grande casserole", 90)},
           {UstensilModel("Spatule en bois", 30), UstensilModel("Fouet", 20)}),

    Recipe(RecipesNames::Burger, RecipesTypes::Meat, 5,
           {"Tomate", "Farine", "Sel"},
           {UstensilModel("Grande casserole", 90)},
           {UstensilModel("Spatule en bois", 30), UstensilModel("Fouet", 20)}),

    Recipe(RecipesNames::Pasta, RecipesTypes::Vegetarian, 6,
           {"Tomate", "Farine", "Sel"},
           {UstensilModel("Grande casserole", 90)},
           {UstensilModel("Spatule en bois", 30), UstensilModel("Fouet", 20)}),

    Recipe(RecipesNames::Salad, RecipesTypes::Vegan, 3,
           {"Tomate", "Farine", "Sel"},
           {UstensilModel("Grande casserole", 90)},
           {UstensilModel("Spatule en bois", 30), UstensilModel("Fouet", 20)}),

    Recipe(RecipesNames::Soup, RecipesTypes::Vegan, 4,
           {"Tomate", "Farine", "Sel"},
           {UstensilModel("Grande casserole", 90)},
           {UstensilModel("Spatule en bois", 30), UstensilModel("Fouet", 20)}),
};

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
        const Recipe& randomRecipe = predefinedRecipes[std::rand() % predefinedRecipes.size()];

        if (order.recipesWithQuantities.contains(randomRecipe)) {
            order.recipesWithQuantities[randomRecipe] += 1; // Augmente la quantité
        } else {
            order.recipesWithQuantities.insert(randomRecipe, 1); // Nouvelle recette
        }

        qDebug() << "Recette ajoutée "
                 << "Quantité actuelle: " << order.recipesWithQuantities[randomRecipe];
    }

    chefModel->addOrder(order);
    qDebug() << "Commande " << order.id << " simulée avec" << order.recipesWithQuantities.size() << "recettes différentes.";
}


ChefModel* ChefController::getChefModel() const {
    return chefModel;
}
