#ifndef COOKMODEL_H
#define COOKMODEL_H

#include <QObject>
#include <QThread>
#include "Order.h"
#include <QMutex>
#include <QSqlDatabase>

class CookModel : public QObject {
    Q_OBJECT

public:
    CookModel();
    ~CookModel();

    bool isAvailable();
    void assignOrder(const Order& order);

signals:
    void orderCompleted(int orderId);
    void orderFailed(int orderId); // Signal pour indiquer l'échec de la commande

private:
    QThread* workerThread;
    Order currentOrder;
    bool available;
    QMutex mutex;

    bool checkResources(const Order& order); // Méthode pour vérifier les ressources

private slots: // Déclarez processOrder comme un slot
    void processOrder();
};

#endif // COOKMODEL_H
