//
// Created by seand on 12/5/2024.
//

#include "../classDeclaration/TableFactory.h"

// vector<Table*> TableFactory::dinningRommTables {};

TableFactory::TableFactory() {
    twoPlacesTablesLeft = 10;
    fourPlacesTablesLeft = 10;
    sixPlacesTablesLeft = 5;
    eightPlacesTablesLeft = 5;
    tenPlacesTablesLeft = 5;
}

TableFactory::~TableFactory() {
}

Table *TableFactory::createTable(int abscice, int intercept, int area, int capacity) {
    Table *table = new Table(abscice, intercept, capacity, area);
    // dinningRoomTables.push_back(table);
    return table;
}


Table* TableFactory::getTableOfTwo(int abscice, int intercept, int area) {
    return createTable(abscice, intercept, area, 2);
}
Table* TableFactory::getTableOfFour(int abscice, int intercept, int area) {
    return createTable(abscice, intercept, area, 4);
}
Table* TableFactory::getTableOfSix(int abscice, int intercept, int area) {
    return createTable(abscice, intercept, area, 6);
}
Table* TableFactory::getTableOfEight(int abscice, int intercept, int area) {
    return createTable(abscice, intercept, area, 8);
}
Table* TableFactory::getTableOfTen(int abscice, int intercept, int area) {
    return createTable(abscice, intercept, area, 10);
}
