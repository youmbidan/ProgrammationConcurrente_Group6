//
// Created by seand on 12/7/2024.
//

#include "../classDeclaration/ClientGroupFactory.h"

ClientGroupFactory::ClientGroupFactory() {};


ClientGroupModel* ClientGroupFactory::createGroup() {
    clientNumber = generateClientNumber();
    vector<ClientModel*> clients;
    cout << "creation de " << clientNumber << " clients " << endl;
    for (int i = 0; i <= clientNumber; i++) {
        clients.push_back(new ClientModel());
    }
    auto* client_group_model = new ClientGroupModel(clients, clientNumber);
    cout << "groupe cree... ajoutons a la queue " << endl;

    return client_group_model;
}

int ClientGroupFactory::generateClientNumber() {

    srand(time(0));
    const int clientNumber = rand() % 10 + 1;
    return clientNumber;
}
