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
    currentCard = {
        Recipe(GAUFRES, DESSERT, 15,
               {"Farine", "Œufs", "Lait", "Sucre"},
               {UstensilModel("Gaufrier", 30)},
               {UstensilModel("Assiette", 10), UstensilModel("Fourchette", 10)}),
        Recipe(Pizza, PLAT, 20,
               {"Pâte à pizza", "Sauce tomate", "Fromage", "Jambon"},
               {UstensilModel("Four", 300)},
               {UstensilModel("Assiette", 10), UstensilModel("Couteau", 10)}),
        Recipe(RATATOUILLE, PLAT, 30,
               {"Courgette", "Aubergine", "Tomate", "Poivron", "Oignon"},
               {UstensilModel("Casserole", 120)},
               {UstensilModel("Assiette creuse", 10), UstensilModel("Cuillère", 10)}),
        Recipe(TIRAMISU, DESSERT, 10,
               {"Mascarpone", "Café", "Biscuits à la cuillère", "Cacao"},
               {UstensilModel("Bol", 60)},
               {UstensilModel("Assiette", 10), UstensilModel("Cuillère", 10)}),
        Recipe(BOLES_DE_PICOULATS, PLAT, 40,
               {"Boulettes de viande", "Tomate", "Oignon", "Vin blanc"},
               {UstensilModel("Poêle", 60)},
               {UstensilModel("Assiette", 10), UstensilModel("Couteau", 10)}),
        Recipe(RIZ_CANTONAIS, PLAT, 25,
               {"Riz", "Petits pois", "Jambon", "Œufs"},
               {UstensilModel("Poêle", 60)},
               {UstensilModel("Assiette", 10), UstensilModel("Cuillère", 10)}),
        Recipe(TARTE_TATIN, DESSERT, 30,
               {"Pommes", "Pâte feuilletée", "Beurre", "Sucre"},
               {UstensilModel("Moule à tarte", 300)},
               {UstensilModel("Assiette", 10), UstensilModel("Fourchette", 10)}),
        Recipe(LASAGNES, PLAT, 50,
               {"Pâte à lasagnes", "Viande hachée", "Béchamel", "Fromage râpé"},
               {UstensilModel("Four", 300)},
               {UstensilModel("Assiette", 10), UstensilModel("Fourchette", 10)}),
        Recipe(GASPATCHO, ENTREE, 15,
               {"Tomate", "Concombre", "Poivron", "Oignon", "Ail"},
               {UstensilModel("Mixeur", 60)},
               {UstensilModel("Verre", 10), UstensilModel("Cuillère", 10)}),
        Recipe(CAFE_GOURMAND, DESSERT, 5,
               {"Café", "Macarons", "Chocolat", "Crème brûlée"},
               {UstensilModel("Machine à café", 60)},
               {UstensilModel("Tasse", 10), UstensilModel("Cuillère", 10)})
    };
}

