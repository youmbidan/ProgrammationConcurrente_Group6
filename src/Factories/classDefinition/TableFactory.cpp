//
// Created by seand on 12/5/2024.
//

#include "../classDeclaration/TableFactory.h"


// Initialisation des compteurs de tables statiques
int TableFactory::twoPlacesTablesLeft = 0;
int TableFactory::fourPlacesTablesLeft = 0;
int TableFactory::sixPlacesTablesLeft = 0;
int TableFactory::eightPlacesTablesLeft = 0;
int TableFactory::tenPlacesTablesLeft = 0;
int TableFactory::idCursor = 1;

// Initialisation du vecteur de tables
std::vector<Table*> TableFactory::dinningRoomTables;


TableFactory::TableFactory() {
    twoPlacesTablesLeft = 10;
    fourPlacesTablesLeft = 10;
    sixPlacesTablesLeft = 5;
    eightPlacesTablesLeft = 5;
    tenPlacesTablesLeft = 5;
    idCursor = 1;
}

TableFactory::~TableFactory() {
}

Table *TableFactory::createTable(int abscice, int intercept, int area, int capacity, int id) {
    Table *table = new Table(abscice, intercept, capacity, area, id);
    dinningRoomTables.push_back(table);
    cout << "Creation de la table avec l'id " << id << endl;
    return table;
}


Table* TableFactory::getTableOfTwo(int abscice, int intercept, int area) {
    twoPlacesTablesLeft--;
    Table* newTable = createTable(abscice, intercept, area, 2, idCursor);
    idCursor++;
    return newTable;
}
Table* TableFactory::getTableOfFour(int abscice, int intercept, int area) {
    fourPlacesTablesLeft--;
    Table* newTable = createTable(abscice, intercept, area, 4, idCursor);
    idCursor++;
    return newTable;
}
Table* TableFactory::getTableOfSix(int abscice, int intercept, int area) {
    sixPlacesTablesLeft--;
    Table* newTable = createTable(abscice, intercept, area, 6, idCursor);
    idCursor++;
    return newTable;
}
Table* TableFactory::getTableOfEight(int abscice, int intercept, int area) {
    eightPlacesTablesLeft--;
    Table* newTable = createTable(abscice, intercept, area, 8, idCursor);
    idCursor++;
    return newTable;
}
Table* TableFactory::getTableOfTen(int abscice, int intercept, int area) {
    tenPlacesTablesLeft--;
    Table* newTable = createTable(abscice, intercept, area, 10, idCursor);
    idCursor++;
    return newTable;
}
