//
// Created by seand on 12/7/2024.
//

#include "../classDeclaration/ClientGroupFactory.h"

ClientGroupFactory::ClientGroupFactory() {};


// void ClientGroupFactory::createGroup() {
//     clientNumber = generateClientNumber();
//     vector<ClientModel*> clients;
//     for (int i = 0; i < clientNumber; i++) {
//         clients[i] = new ClientModel();
//     }
//     auto* client_group_model = new ClientGroupModel(clients, clientNumber);

//     clientGroupQueue.emplace(client_group_model);

// }

// int ClientGroupFactory::generateClientNumber() {
//     constexpr int min = 1;
//     constexpr int max = 10;

//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<> distrib(min, max);

//     const int randomValue = distrib(gen);

//     return randomValue;
// }
