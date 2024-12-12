//
// Created by franck on 12/2/24.
//
#include "../classDeclaration/ClientGroupModel.h"

ClientGroupModel::ClientGroupModel(double abscice, double intercept, const vector<ClientModel*> client_group, int client_number)
        :   MobileElementModel(abscice, intercept),
            clientGroup(client_group), clientNumber(client_number) {
}

int ClientGroupModel::getClientNumber() const {
    return clientNumber;
}


void ClientGroupModel::setCoords(const PointStruct newCoords) {
    abscice = newCoords.x;
    intercept = newCoords.y;
}

void ClientGroupModel::move(PointStruct finalCoords) {
    std::cout << "[ClientGroupModel] Calling MobilePointModel::move" << std::endl;
    MobileElementModel::move(finalCoords);
}

vector<ClientModel*> ClientGroupModel::getClientGroup() {
    return clientGroup;
}

