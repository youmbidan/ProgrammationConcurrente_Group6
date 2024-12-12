#ifndef RECIPE_H
#define RECIPE_H

#include <QString>
#include <QStringList>
#include <QVector>
#include "UstensilModel.h"

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

    QStringList ingredientList; // Liste des ingrédients
    QVector<UstensilModel> cookingUstensilsList; // Ustensiles pour cuisiner
    QVector<UstensilModel> eatingUstensils; // Ustensiles pour manger

    Recipe(); // Constructeur par défaut
    Recipe(RecipesNames name, RecipesTypes type, int cookingTime,
           QStringList ingredientList, QVector<UstensilModel> cookingUstensilsList,
           QVector<UstensilModel> eatingUstensils);

    QString toString() const; // Pour un affichage lisible
    QStringList getIngredients() const;
    QStringList getUstensils() const;
    int getCookingTime() const;
    bool operator<(const Recipe& other) const {
        return static_cast<int>(name) < static_cast<int>(other.name);
    }

};

#endif // RECIPE_H
