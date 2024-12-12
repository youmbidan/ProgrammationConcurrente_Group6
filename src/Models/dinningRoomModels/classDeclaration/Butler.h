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
     */
    Butler()= default;

    /**
     * @brief to assign a table to a group of client according
     * to their number
     *
     * @param clientNumber
     * @param freeTableList
     */
    Table* assignTable(int clientNumber, vector<Table*>& freeTableList);

    /**
     * @brief to notify a headwaiter tha he has to take a client
     * to his table
     *
     * @param table
     * @param client
     */
    void notifyHeadWaiter(Table table, ClientModel client);

private:
    const vector<int> priority_table {10, 8, 6, 4, 2};
    std::mutex freeTablesMutex;

};
#endif //BUTLE_H
