#include "ChefController.h"
#include <QDebug>

ChefController::ChefController(ChefModel* chefModel)
    : chefModel(chefModel), nextOrderId(1) {}

void ChefController::simulateIncomingOrder() {
    Order order(nextOrderId++, QString("Détails de la commande %1").arg(nextOrderId));
    chefModel->addOrder(order);
    qDebug() << "Commande simulée" << order.id;
}

ChefModel* ChefController::getChefModel() const {
    return chefModel;
}
