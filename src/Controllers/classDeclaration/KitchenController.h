#ifndef KITCHENCONTROLLER_H
#define KITCHENCONTROLLER_H

#include <QObject>
#include "../../Models/kitchenModels/classDeclaration/Chief.h"
#include <queue>
#include "../classDeclaration/SharedOrdersQueue.h"



class KitchenController : public QObject {
    Q_OBJECT

public:

    explicit KitchenController(ChiefModel *chefModel,  SharedOrdersQueue& sharedOrdersQueue, QObject *parent = nullptr);

    ChiefModel* getChiefModel() const;

    std::queue<Order*> ordersOnCounterQueue;
    std::queue<Order*> ordersReadyOnCounterQueue;

    void processOrders();

    // public slots:
    //     void receiveOrder(Order* order);

    // signals:
    //     void orderCompleted(int orderId);

private:
    ChiefModel* chiefModel;
    int nextOrderId;
    SharedOrdersQueue& sharedOrdersQueue;

};

#endif // KITCHENCONTROLLER_H
