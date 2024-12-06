//
// Created by seand on 12/5/2024.
//

#ifndef TABLEFACTORY_H
#define TABLEFACTORY_H
#include "../../Models/dinningRoomModels/classDeclaration/Table.h"

/**
 * @class TableFactory
 *
 * @brief for table generation according to theirs type
 * (e.g, 2 places tables or 4 places tables...)
 */

class TableFactory {
 int twoPlacesTablesLeft;
 int fourPlacesTablesLeft;
 int sixPlacesTablesLeft;
 int eightPlacesTablesLeft;
 int tenPlacesTablesLeft;

public:
 TableFactory();
 ~TableFactory();

 Table* getTableOftwo(int abscice, int intercept){};
 Table* getTableOfFour(int abscice, int intercept){};
 Table* getTableOfSix(int abscice, int intercept){};
 Table* getTableOfEight(int abscice, int intercept){};
 Table* getTableOfTen(int abscice, int intercept){};


};



#endif //TABLEFACTORY_H
