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
class ClientGroupModel : public MobileElementModel {
public:
    /**
     * @brief the clientGroup class constructor
     *
     * @param abscice
     * @param intercept
     * @param client_group
     * @param client_number
     */
    ClientGroupModel(double abscice, double intercept, const vector<ClientModel*> client_group, int client_number);

    /**
     * @brief setters and guetters
     */

    int getClientNumber() const;

    vector<ClientModel*> getClientGroup();

    void setCoords(PointStruct newCoords);

    void move(PointStruct finalCoords);

private:
    vector<ClientModel*> clientGroup;
    int clientNumber;
    double abscice;
    double intercept;

};
#endif //CLIENTGROUPMODEL_H
