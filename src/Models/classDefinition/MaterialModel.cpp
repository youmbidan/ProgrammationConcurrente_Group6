#include "../classDeclaration/MaterialModel.h"
//
// Created by franck on 12/2/24.
//
bool MaterialModel::get_isActive() const {
    return isActive;
}
void MaterialModel::toogle_isActive() {
    isActive = !isActive;
}

