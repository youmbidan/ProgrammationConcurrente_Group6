#include "../classDeclaration/CardModel.h"
//
// Created by franck on 12/2/24.
//

CardModel::CardModel() {
    initializeCard();
};


vector<Recipe> &CardModel::getCurrentCard() {
    return currentCard;
}


void CardModel::initializeCard() {
    // Cooking Utensils
    UstensilModel whisk("Whisk", 5);
    UstensilModel pan("Frying Pan", 10);
    UstensilModel mixingBowl("Mixing Bowl", 7);
    UstensilModel blender("Blender", 8);
    UstensilModel knife("Knife", 6);
    UstensilModel spatula("Spatula", 5);
    UstensilModel pot("Cooking Pot", 12);
    UstensilModel grill("Grill Pan", 15);

    // Eating Utensils
    UstensilModel fork("Fork", 3);
    UstensilModel spoon("Spoon", 3);
    UstensilModel plate("Plate", 5);
    UstensilModel bowlPlate("Bowl Plate", 6);

    // Recipe 1: Gaufres (Waffles - Dessert)
    vector<UstensilModel> gaufresCookingUtensils = {whisk, mixingBowl, pan, spatula};
    vector<UstensilModel> gaufresEatingUtensils = {fork, plate};
    Recipe gaufres(
        GAUFRES,
        DESSERT,
        30,  // cooking time in minutes
        {"flour", "eggs", "milk", "butter", "sugar", "vanilla extract"},
        gaufresCookingUtensils,
        gaufresEatingUtensils
    );

    // Recipe 2: Crepes (Crepes - Dessert)
    vector<UstensilModel> crepesCookingUtensils = {whisk, mixingBowl, pan, spatula};
    vector<UstensilModel> crepesEatingUtensils = {fork, plate};
    Recipe crepes(
        CREPES,
        DESSERT,
        25,  // cooking time in minutes
        {"flour", "eggs", "milk", "butter", "salt"},
        crepesCookingUtensils,
        crepesEatingUtensils
    );

    // Recipe 3: Boulinades d'Anguille ou de Poisson (Fish Stew - Plat)
    vector<UstensilModel> boulinadesCookingUtensils = {knife, pot, mixingBowl, spatula};
    vector<UstensilModel> boulinadesEatingUtensils = {fork, spoon, plate};
    Recipe boulinades(
        BOULINADES_DANGUILLE_OU_DE_POISSON,
        PLAT,
        60,  // cooking time in minutes
        {"fish", "onions", "tomatoes", "garlic", "olive oil", "herbs", "salt", "pepper"},
        boulinadesCookingUtensils,
        boulinadesEatingUtensils
    );

    // Recipe 4: Boles de Picoulats (Catalan Meatballs - Plat)
    vector<UstensilModel> bolesCookingUtensils = {knife, mixingBowl, grill, spatula};
    vector<UstensilModel> bolesEatingUtensils = {fork, plate};
    Recipe bolesDePicoulats(
        BOLES_DE_PICOULATS,
        PLAT,
        45,  // cooking time in minutes
        {"ground meat", "eggs", "breadcrumbs", "garlic", "parsley", "salt", "pepper"},
        bolesCookingUtensils,
        bolesEatingUtensils
    );

    // Recipe 5: Gaspatcho (Cold Soup - Entree)
    vector<UstensilModel> gaspatchoCookingUtensils = {knife, blender, mixingBowl};
    vector<UstensilModel> gaspatchoEatingUtensils = {spoon, bowlPlate};
    Recipe gaspatcho(
        GASPATCHO,
        ENTREE,
        20,  // preparation time in minutes
        {"tomatoes", "cucumber", "bell pepper", "garlic", "olive oil", "vinegar", "salt", "pepper"},
        gaspatchoCookingUtensils,
        gaspatchoEatingUtensils
    );

    // Recipe 6: Pate de Sanglier (Wild Boar Pate - Entree)
    vector<UstensilModel> pateCookingUtensils = {knife, mixingBowl, blender};
    vector<UstensilModel> pateEatingUtensils = {fork, spoon, plate};
    Recipe pateDeSanglier(
        PATE_DE_SANGLIER,
        ENTREE,
        90,  // preparation time in minutes
        {"wild boar meat", "liver", "bacon", "onions", "garlic", "cognac", "herbs", "salt", "pepper"},
        pateCookingUtensils,
        pateEatingUtensils
    );

    // Clear any existing recipes and add the new ones
    currentCard.clear();
    currentCard.push_back(gaufres);
    currentCard.push_back(crepes);
    currentCard.push_back(boulinades);
    currentCard.push_back(bolesDePicoulats);
    currentCard.push_back(gaspatcho);
    currentCard.push_back(pateDeSanglier);
}

