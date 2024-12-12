//
// Created by seand on 12/11/2024.
//

#ifndef ATTRIBUTION_H
#define ATTRIBUTION_H
#include "../Models/commonModels/classDeclaration/ClientGroupModel.h"
#include "../Models/dinningRoomModels/classDeclaration/Table.h"

struct Attribution {
    ClientGroupModel *clientGroup;
    Table* tableAssociated;
};


#endif //ATTRIBUTION_H
