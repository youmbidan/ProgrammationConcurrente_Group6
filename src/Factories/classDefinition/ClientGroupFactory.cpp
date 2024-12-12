//
// Created by seand on 12/7/2024.
//

#include "../classDeclaration/ClientGroupFactory.h"

ClientGroupFactory::ClientGroupFactory() {};


ClientGroupModel* ClientGroupFactory::createGroup() {
    clientNumber = generateClientNumber();
    cout << "creation d'un groupe de : " << clientNumber << " clients (ClientGroupFactory::createGroup())" << endl;
    vector<ClientModel*> clients;
    for (int i = 0; i <= clientNumber; i++) {
        clients.push_back(new ClientModel());
    }
    auto* client_group_model = new ClientGroupModel(0,0, clients, clientNumber);

    return client_group_model;
}

int ClientGroupFactory::generateClientNumber() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);

    return dis(gen);
}
