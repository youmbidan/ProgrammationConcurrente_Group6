//
// Created by franck on 12/2/24.
//

#ifndef HEADWAITER_H
#define HEADWAITER_H
#include "../../commonModels/classDeclaration/Order.h"
#include "Table.h"
#include "../../commonModels/classDeclaration/ClientModel.h"
#include <queue>
/**
 * @class HeadWaiter
 *
 * @brief the guys who lead the client to his table
 */
class HeadWaiter : public MobileElementModel {
    queue<Order> orderQueue;
public:

    HeadWaiter(int abscice, int intercept);
    /**
     * @brief the function to lead the clients to their table
     *
     * @param table
     * @param clients
     */
    void leadClients(Table &table, vector<ClientModel> &clients);

    /**
     * @brief the function to take order and pass it to the chief
     */
    void passOrdersTochief();
};
#endif //HEADWAITER_H
