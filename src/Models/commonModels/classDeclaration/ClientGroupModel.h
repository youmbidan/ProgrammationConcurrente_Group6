//
// Created by franck on 12/2/24.
//

#ifndef CLIENTGROUPMODEL_H
#define CLIENTGROUPMODEL_H
#include <vector>
#include <random>
#include "ClientModel.h"

using namespace std;

/**
 * @class ClientGroupModel
 *
 * @brief the generations of clients group
 */
class ClientGroupModel {
public:
    /**
     * @brief the clientGroup class constructor
     *
     * @param client_group
     * @param client_number
     */
    ClientGroupModel(const vector<ClientModel*> &client_group, int client_number)
        : clientGroup(client_group)
         {}

    /**
     * @brief setters and guetters
     */
    void setClientGroup(const vector<ClientModel> &client_group);

    int getClientNumber();

    vector<ClientModel> getClientGroup();

    int getIntercept();

    int getAbscice();

    void setAbscice(int abscice);

    void setIntercept(int intercept);

private:
    vector<ClientModel*> clientGroup;
    int clientNumber;
    int abscice;
    int intercept;

};
#endif //CLIENTGROUPMODEL_H
