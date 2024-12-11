#ifndef RECIPE_H
#define RECIPE_H

#include <QString>

enum class RecipesNames {
    Pizza,
    Burger,
    Pasta,
    Salad,
    Soup
};

enum class RecipesTypes {
    Vegetarian,
    Vegan,
    Meat
};

class Recipe {
public:
    RecipesNames name;
    RecipesTypes type;
    int cookingTime; // Temps de cuisson en minutes

    Recipe(); // Constructeur par défaut
    Recipe(RecipesNames name, RecipesTypes type, int cookingTime);

    QString toString() const; // Pour un affichage lisible
};

#endif // RECIPE_H
