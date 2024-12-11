#include "Recipe.h"

Recipe::Recipe()
    : name(RecipesNames::Pizza), type(RecipesTypes::Vegetarian), cookingTime(10) {} // Valeurs par défaut

Recipe::Recipe(RecipesNames name, RecipesTypes type, int cookingTime)
    : name(name), type(type), cookingTime(cookingTime) {}

QString Recipe::toString() const {
    return QString("Nom: %1, Type: %2, Temps de cuisson: %3 minutes")
    .arg(static_cast<int>(name))
        .arg(static_cast<int>(type))
        .arg(cookingTime);
}
