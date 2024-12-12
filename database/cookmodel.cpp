#include "CookModel.h"
#include <QTimer>
#include <QDebug>

CookModel::CookModel() : available(true) {
    workerThread = new QThread();
    moveToThread(workerThread);
    workerThread->start();
}

CookModel::~CookModel() {
    workerThread->quit();
    workerThread->wait();
    delete workerThread;
}

bool CookModel::isAvailable() {
    QMutexLocker locker(&mutex); // Assure un accès thread-safe
    return available;
}

void CookModel::assignOrder(const Order& order) {
    QMutexLocker locker(&mutex);
    if (!available) {
        qWarning() << "Cuisinier non disponible. Commande ignorée.";
        return;
    }

    currentOrder = order;
    available = false;

    qDebug() << "Commande" << order.id << "assignée à un cuisinier.";
    QMetaObject::invokeMethod(this, "processOrder", Qt::QueuedConnection);
}

void CookModel::processOrder() {
    QTimer::singleShot(3000, this, [this]() { // Simule un délai de 3 secondes
        QMutexLocker locker(&mutex);
        available = true;
        emit orderCompleted(currentOrder.id);
        qDebug() << "Commande" << currentOrder.id << "terminée.";
    });
}
