//
// Created by franck on 12/2/24.
//

#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <vector>

#include "../../commonModels/classDeclaration/ClientModel.h"

/**
 * @class Table
 *
 * @brief the class table for the management of all the table of
 * the dinning room
 */
class Table {
public:
    /**
     * @brief Constructor of the class Table
     *
     * @param abscice
     * @param intercept
     * @param capacity
     * @param area
     */
    Table(double abscice, double intercept, int capacity, int area, int id)
        : abscice(abscice),
          intercept(intercept),
          capacity(capacity),
            area(area), id(id){
    }

    /**
     * @brief a function to add clients on the table
     *
     * @param clients
     */
    void addClientsToTable(vector<ClientModel*> clients);

    /**
     * @brief to move the client when they have finished eating
     */
    void releaseClients();

    void setAbscice(double abscice);
    void setIntercept(double intercept);
    void setOccuped(int occuped);
    void setClientList(vector<ClientModel*> clientList);

    vector<ClientModel*> getClientsOnTable();

    int getCapacity();
    double getAbscice();
    double getIntercept();
    int getTableId();


private:
    int id;
    int area;
    double abscice;
    double intercept;
    int capacity;
    int occuped;
    vector<ClientModel*> clientList;
    int breadCartNeeded;

};
#endif //TABLE_H
