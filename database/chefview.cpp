#include "ChefView.h"

ChefView::ChefView(ChefController* controller, QWidget *parent)
    : QWidget(parent), controller(controller) {

    addOrderButton = new QPushButton("Ajouter une commande", this);
    orderListWidget = new QListWidget(this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(addOrderButton);
    layout->addWidget(orderListWidget);

    connect(addOrderButton, &QPushButton::clicked, this, &ChefView::onAddOrderClicked);
    connect(controller->getChefModel(), &ChefModel::orderCompleted, this, &ChefView::onOrderCompleted);


}

void ChefView::onAddOrderClicked() {
    controller->simulateIncomingOrder();
    orderListWidget->addItem("Nouvelle commande ajoutée.");
}

void ChefView::onOrderCompleted(int orderId) {
    orderListWidget->addItem("Commande " + QString::number(orderId) + " terminée.");
}
