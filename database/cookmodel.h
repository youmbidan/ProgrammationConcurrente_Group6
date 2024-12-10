#ifndef COOKMODEL_H
#define COOKMODEL_H

#include <QObject>
#include <QThread>
#include "Order.h"
#include <QMutex>

class CookModel : public QObject {
    Q_OBJECT

public:
    CookModel();
    ~CookModel();

    bool isAvailable();
    void assignOrder(const Order& order);

signals:
    void orderCompleted(int orderId);

private:
    QThread* workerThread;
    Order currentOrder;
    bool available;
    QMutex mutex;

private slots: // Déclarez processOrder comme un slot
    void processOrder();
};

#endif // COOKMODEL_H
