//
// Created by franck on 12/2/24.
//
#include "../classDeclaration/ClientModel.h"


void ClientModel::makeChoice(vector<Recipe> &recipes) {
    // Check if the recipes vector is empty
    if (recipes.empty()) {
        // Handle empty vector case (could throw an exception or return a default recipe)
        throw std::runtime_error("No recipes available to choose from");
    }

    // Create a random number generator
    random_device rd;  // Used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

    // Create a uniform distribution across the range of recipes
    uniform_int_distribution<> distrib(0, recipes.size() - 1);

    // Generate a random index
    int randomIndex = distrib(gen);

    // Return the randomly selected recipe
    // recipes[randomIndex];
}

void ClientModel::toogleHasOrdered() {
    this->hasOdered = !this->hasOdered;
}

void ClientModel::toogleHasOrderedMainCourse() {
    this->hasOrderedMainCourse = !this->hasOrderedMainCourse;
}

void ClientModel::toogleHasOrderedDessert() {
    this->hasOrderedDessert = !this->hasOrderedDessert;
}

void ClientModel::toogleHasOrderedEntree() {
    this->hasOrderedEntree = !this->hasOrderedEntree;
}

void ClientModel::setChoice(Recipe* choiceMade) {
    choice = choiceMade;
}
// void ClientModel::eat(Order order) {
    //  Manage the time by the type of dishes
// }

Recipe* ClientModel::getChoice() {
    return choice;
}

