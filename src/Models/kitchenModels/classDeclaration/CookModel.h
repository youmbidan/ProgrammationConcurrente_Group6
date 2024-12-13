#ifndef COOKMODEL_H
#define COOKMODEL_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QTimer>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "../../commonModels/classDeclaration/Order.h"

class CookModel : public QObject {
    Q_OBJECT

public:
    CookModel();
    ~CookModel();

    bool isAvailable();                // Vérification de la disponibilité
    void assignOrder(const Order* order);    // Assigner une commande à ce cuisinier

    signals:
        void orderCompleted(int orderId);        // Signal pour indiquer la fin de la commande
    void orderFailed(int orderId);           // Signal pour indiquer l'échec de la commande

private:
    QThread* workerThread;
    const Order *currentOrder;
    bool available;
    QMutex mutex;

    bool checkResources(const Order* order); // Vérification des ressources nécessaires

    private slots:
        void processOrder(); // Traiter la commande
};

#endif // COOKMODEL_H
