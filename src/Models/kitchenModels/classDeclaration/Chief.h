#ifndef CHEFMODEL_H
#define CHEFMODEL_H

#include <QObject>
#include <QQueue>
#include <QThread>
#include <QList>
#include <QMutex>
#include <QWaitCondition>
#include "../../commonModels/classDeclaration/Order.h"
#include "CookModel.h"

class ChiefModel : public QObject {
 Q_OBJECT

public:
 ChiefModel();
 ~ChiefModel();

 void addOrder(const Order* order);
 void addCook(CookModel* cook);

private:
 QQueue<Order> pendingOrders;
 QList<CookModel*> cooks;
 QMutex mutex;
 QWaitCondition ordersAvailable;

 void distributeOrders();

 signals:
     void orderCompleted(int orderId);

};

#endif // CHEFMODEL_H
