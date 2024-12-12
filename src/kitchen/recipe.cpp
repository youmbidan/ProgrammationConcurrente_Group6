#include "Recipe.h"

Recipe::Recipe()
    : name(RecipesNames::Pizza), type(RecipesTypes::Vegetarian), cookingTime(10) {}

Recipe::Recipe(RecipesNames name, RecipesTypes type, int cookingTime,
               QStringList ingredientList, QVector<UstensilModel> cookingUstensilsList,
               QVector<UstensilModel> eatingUstensils)
    : name(name), type(type), cookingTime(cookingTime),
    ingredientList(ingredientList), cookingUstensilsList(cookingUstensilsList),
    eatingUstensils(eatingUstensils) {}

QString Recipe::toString() const {
    QString cookingUstensilsStr;
    for (const auto& ustensil : cookingUstensilsList) {
        cookingUstensilsStr += ustensil.toString() + ", ";
    }

    QString eatingUstensilsStr;
    for (const auto& ustensil : eatingUstensils) {
        eatingUstensilsStr += ustensil.toString() + ", ";
    }

    return QString("Nom: %1, Type: %2, Temps de cuisson: %3 minutes\nIngrédients: %4\n"
                   "Ustensiles de cuisson: %5\nUstensiles pour manger: %6")
        .arg(static_cast<int>(name))
        .arg(static_cast<int>(type))
        .arg(cookingTime)
        .arg(ingredientList.join(", "))
        .arg(cookingUstensilsStr)
        .arg(eatingUstensilsStr);
}

QStringList Recipe::getIngredients() const {
    return ingredientList;
}

QStringList Recipe::getUstensils() const {
    QStringList ustensils;
    for (const auto& ustensil : cookingUstensilsList) {
        ustensils.append(ustensil.toString());
    }
    for (const auto& ustensil : eatingUstensils) {
        ustensils.append(ustensil.toString());
    }
    return ustensils;
}

int Recipe::getCookingTime() const {
    return cookingTime;
}
