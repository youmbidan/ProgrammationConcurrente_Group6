//
// Created by seand on 12/7/2024.
//

#ifndef CLIENTGROUPFACTORY_H
#define CLIENTGROUPFACTORY_H
#include <queue>

#include "../../Models/commonModels/classDeclaration/ClientGroupModel.h"
#include  "../../Models/commonModels/classDeclaration/ClientModel.h"
#include <condition_variable>


class ClientGroupFactory {
    static queue<ClientGroupModel*> clientGroupQueue;
    int clientNumber;

    /**
     * @brief create group according to generated client number
     */
    // void createGroup();

    /**
   *@brief generate number that will be used as value for our variable "clientNumber"
    */
    // static int generateClientNumber();




public:
    ClientGroupFactory();

};



#endif //CLIENTGROUPFACTORY_H
