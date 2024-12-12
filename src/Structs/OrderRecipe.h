//
// Created by seand on 12/12/2024.
//

#ifndef ORDERRECIPE_H
#define ORDERRECIPE_H

#include "../Models/commonModels/classDeclaration/Recipe.h"

struct OrderRecipe {
    Recipe* recipe;
    int quantity;
};

#endif //ORDERRECIPE_H
