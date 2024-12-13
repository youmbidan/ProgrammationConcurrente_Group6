#include "../classDeclaration/Order.h"

int Order::getTotalCookingTime() const {
    int totalTime = 0;
    for (const auto& orderRecipe : orderRecipes) {
        int subTotal = orderRecipe->recipe->getCookingTime()*orderRecipe->quantity;
        totalTime += subTotal ; // Supposons que chaque recette a une méthode getCookingTime()
    }
    return totalTime;
}
