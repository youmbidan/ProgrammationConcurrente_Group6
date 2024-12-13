#ifndef KITCHENCONTROLLER_H
#define KITCHENCONTROLLER_H

#include <QObject>
#include "../../Models/kitchenModels/classDeclaration/Chief.h"
#include <queue>

class KitchenController : public QObject {
    Q_OBJECT

public:
    explicit KitchenController(ChiefModel* chefModel,  QObject* parent = nullptr);

    ChiefModel* getChiefModel() const;

    void processOrder();
    std::queue<Order*> ordersOnCounterQueue;
    std::queue<Order*> ordersReadyOnCounterQueue;

    // public slots:
    //     void receiveOrder(Order* order);

    // signals:
    //     void orderCompleted(int orderId);

private:
    ChiefModel* chiefModel;
    int nextOrderId;
};

#endif // KITCHENCONTROLLER_H
