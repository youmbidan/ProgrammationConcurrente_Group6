//
// Created by franck on 12/2/24.
//

#ifndef BUTLE_H
#define BUTLE_H
#include <vector>
#include "Table.h"
#include "../../commonModels/classDeclaration/ClientModel.h"
using namespace std;

/**
 * @class Butler
 *
 * the class of the butler (he is supposed to welcome the client at their
 * entry)
 */
class Butler {
public:
    /**
     * @brief Constructor of the class Butler
     *
     * @param client_number
     * @param priority_table
     */
    Butler(){}

    /**
     * @brief to assign a table to a group of client according
     * to their number
     *
     * @param clientNumber
     */
    Table* assignTable(int clientNumber, vector<Table*> freeTableList);

    /**
     * @brief to notify a headwaiter tha he has to take a client
     * to his table
     *
     * @param table
     * @param client
     */
    void notifyHeadWaiter(Table table, ClientModel client);

private:
    int clientNUmber;
    const vector<int> priority_table {2, 4, 6, 8, 10};
};
#endif //BUTLE_H
