#include "../classDeclaration/CookModel.h"

CookModel::CookModel() : available(true) {
    // Aucune création de thread QThread, mais on utilisera enqueue pour gérer les tâches en arrière-plan
}

CookModel::~CookModel() {
    // Pas de nettoyage lié à QThread nécessaire ici
}

bool CookModel::isAvailable() {
    QMutexLocker locker(&mutex);
    return available;
}

void CookModel::assignOrder(const Order* order) {
    QMutexLocker locker(&mutex);
    if (!available) {
        qWarning() << "[CookModel] Cuisinier non disponible. Commande ignorée.";
        return;
    }

    if (!checkResources(order)) {
        qWarning() << "[CookModel] Commande" << order->getTableId() << "non terminée : Ressources insuffisantes.";
        emit orderFailed(order->getTableId());
        return;
    }

    currentOrder = order; // Copie de l'objet Order
    available = false;

    qDebug() << "[CookModel] Commande" << order->getTableId() << "assignée à un cuisinier.";
    // Utiliser enqueue pour exécuter le traitement de la commande dans un thread du thread pool
    ThreadPoolManager::enqueue([this]() { processOrder(); });
}

bool CookModel::checkResources(const Order* order) {
    // Vérification des ressources (votre code reste inchangé ici)
    return true;
}

void CookModel::processOrder() {
    int cookingTime = currentOrder->getTotalCookingTime() * 1000; // Convertir en millisecondes
    qDebug() << "[CookModel] Temps total pour la commande :" << cookingTime << "ms.";

    // Utilisation de QTimer pour simuler le délai de cuisson
    QTimer::singleShot(cookingTime, this, [this]() {
        QMutexLocker locker(&mutex);
        available = true;

        emit orderCompleted(currentOrder->getTableId());
        qDebug() << "[CookModel] Commande" << currentOrder->getTableId() << "terminée.";
    });
}
