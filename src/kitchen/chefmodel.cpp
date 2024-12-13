#include "ChefModel.h"
#include <QDebug>

ChefModel::ChefModel() {
    // Lancer un thread pour surveiller les commandes en attente
    QThread* distributorThread = QThread::create([this]() {
        while (true) {
            distributeOrders();
            QThread::msleep(500); // Pause pour réduire l'utilisation du CPU
        }
    });
    distributorThread->start();
}

ChefModel::~ChefModel() {
    // Nettoyage (si nécessaire)
}

void ChefModel::addOrder(const Order& order) {
    QMutexLocker locker(&mutex);
    pendingOrders.enqueue(order);
    qDebug() << "Commande" << order.id << "ajoutée à la file d'attente.";
}

void ChefModel::addCook(CookModel* cook) {
    QMutexLocker locker(&mutex);
    cooks.append(cook);

    // Connecter le signal du cuisinier pour savoir quand il est libre
    connect(cook, &CookModel::orderCompleted, this, [this](int orderId) {
        qDebug() << "Commande" << orderId << "complétée. Cuisinier libre";
        distributeOrders(); // Réattribuer les commandes en attente
    });
}

void ChefModel::distributeOrders() {
    QMutexLocker locker(&mutex);

    for (auto* cook : cooks) {
        if (!cook->isAvailable() || pendingOrders.isEmpty()) {
            continue; // Passer si le cuisinier est occupé ou si aucune commande n'est en attente
        }

        Order order = pendingOrders.dequeue();
        cook->assignOrder(order);

        // Connecter le signal du cuisinier pour notifier que la commande est terminée
        connect(cook, &CookModel::orderCompleted, this, [this](int orderId) {
            emit orderCompleted(orderId); // Notifie que la commande est terminée
        });

        qDebug() << "Commande" << order.id << "attribuée à un cuisinier.";
    }
}

