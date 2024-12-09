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
 static Table* createTable(int abscice, int intercept, int area, int capacity);

public:
 static vector<Table *> dinningRommTables;

 TableFactory();
 ~TableFactory();


 static Table* getTableOfTwo(int abscice, int intercept, int area);
 static Table* getTableOfFour(int abscice, int intercept, int area);
 static Table* getTableOfSix(int abscice, int intercept, int area);
 static Table* getTableOfEight(int abscice, int intercept, int area);
 static Table* getTableOfTen(int abscice, int intercept, int area);

 // static vector<Table*> dinningRoomTables;


};



#endif //TABLEFACTORY_H
