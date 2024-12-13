//
// Created by seand on 12/13/2024.
//

#include "../classDeclaration/KitchenController.h"


#include "../../Models/commonModels/classDeclaration/Recipe.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <vector>

SharedOrdersQueue sharedOrderQueue;

KitchenController::KitchenController(ChiefModel* chefModel,  SharedOrdersQueue& sharedOrdersQueue, QObject* parent)
    : QObject(parent), chiefModel(chefModel), sharedOrdersQueue(sharedOrdersQueue) {}

ChiefModel* KitchenController::getChiefModel() const {
    return chiefModel;
}

//
// void KitchenController::receiveOrder(Order *order) {
//     chiefModel->addOrder(order);
// }

void KitchenController::processOrders() {
        ThreadPoolManager::enqueue([this]() {
            while (true) {
                Order order = sharedOrdersQueue.getOrder();
                std::cout << "KitchenController: Traitement de la commande : " << order.getTableId() << std::endl;

                // Simuler le traitement de la commande
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
        });

}



