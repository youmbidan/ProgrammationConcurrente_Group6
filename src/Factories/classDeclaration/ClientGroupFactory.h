//
// Created by seand on 12/7/2024.
//

#ifndef CLIENTGROUPFACTORY_H
#define CLIENTGROUPFACTORY_H

#include "../../Models/commonModels/classDeclaration/ClientGroupModel.h"


class ClientGroupFactory {
    int clientNumber;

    /**
     * @brief create group according to generated client number
     */

    /**
   *@brief generate number that will be used as value for our variable "clientNumber"
    */
    static int generateClientNumber();




public:
    ClientGroupModel* createGroup();
    ClientGroupFactory();

};



#endif //CLIENTGROUPFACTORY_H
