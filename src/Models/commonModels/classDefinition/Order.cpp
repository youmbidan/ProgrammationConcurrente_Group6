#include "../classDeclaration/Order.h"
#include "../classDeclaration/Recipe.h" // Include recipe header
#include <QString> // Include for string manipulation

int Order::getTotalCookingTime() const {
    int totalTime = 0;
    for (const auto& orderRecipe : orderRecipes) {
        int subTotal = orderRecipe->recipe->getCookingTime() * orderRecipe->quantity;
        totalTime += subTotal;
    }
    return totalTime;
}

