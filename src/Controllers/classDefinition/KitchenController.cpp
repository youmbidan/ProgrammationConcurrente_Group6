//
// Created by seand on 12/13/2024.
//

#include "../classDeclaration/KitchenController.h"


#include "../../Models/commonModels/classDeclaration/Recipe.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <vector>


KitchenController::KitchenController(ChiefModel* chefModel, QObject* parent)
    : QObject(parent), chiefModel(chefModel) {}

ChiefModel* KitchenController::getChiefModel() const {
    return chiefModel;
}

//
// void KitchenController::receiveOrder(Order *order) {
//     chiefModel->addOrder(order);
// }



