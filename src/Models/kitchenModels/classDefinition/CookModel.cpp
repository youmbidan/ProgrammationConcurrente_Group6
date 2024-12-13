#include "../classDeclaration/CookModel.h"

CookModel::CookModel() : available(true) {
    workerThread = new QThread();
    moveToThread(workerThread);
    workerThread->start();
}

CookModel::~CookModel() {
    if (workerThread) {
        workerThread->quit();
        workerThread->wait();
        delete workerThread;
    }
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
    QMetaObject::invokeMethod(this, "processOrder", Qt::QueuedConnection);
}

bool CookModel::checkResources(const Order* order) {
    // QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    // db.setDatabaseName("C:/Users/Donald/Documents/projets_qt/database/masterchef.db");
    //
    // if (!db.open()) {
    //     qCritical() << "Erreur : Impossible d'ouvrir la base de données" << db.lastError().text();
    //     return false;
    // }
    //
    // qDebug() << "Connexion à la base de données réussie.";
    //
    // for (auto it = order.recipesWithQuantities.cbegin(); it != order.recipesWithQuantities.cend(); ++it) {
    //     const Recipe& recipe = it.key();
    //     int quantity = it.value();
    //
    //     // Vérification des ingrédients
    //     for (const QString& ingredient : recipe.getIngredients()) {
    //         QSqlQuery query;
    //         query.prepare("SELECT quantity FROM ingredients WHERE name = :name");
    //         query.bindValue(":name", ingredient);
    //
    //         if (!query.exec() || !query.next()) {
    //             qWarning() << "Ingrédient non disponible :" << ingredient;
    //             db.close();
    //             return false;
    //         }
    //
    //         int availableQuantity = query.value(0).toInt();
    //         if (availableQuantity < quantity) {
    //             qWarning() << "Stock insuffisant pour l'ingrédient :" << ingredient
    //                        << ". Requis:" << quantity << ", Disponible:" << availableQuantity;
    //             db.close();
    //             return false;
    //         }
    //     }
    //
    //     // Vérification des ustensiles (similaire)
    //     //for (const QString& ustensil : recipe.getUstensils()) {
    //        // QSqlQuery query;
    //         //query.prepare("SELECT available FROM ustensils_kitchen WHERE name = :name");
    //         //query.bindValue(":name", ustensil);
    //
    //         //if (!query.exec() || !query.next()) {
    //            //qWarning() << "Ustensile non disponible :" << ustensil;
    //             //db.close();
    //             //return false;
    //         //}
    //
    //         //bool isAvailable = query.value(0).toBool();
    //         //if (!isAvailable) {
    //             //qWarning() << "Ustensile non utilisable :" << ustensil;
    //             //db.close();
    //             //return false;
    //         //}
    //     //}
    // }
    //
    // db.close();
    return true;
}

void CookModel::processOrder() {
    int cookingTime = currentOrder->getTotalCookingTime() * 1000; // Convertir en millisecondes
    qDebug() << "[CookModel] Temps total pour la commande :" << cookingTime << "ms.";

    QTimer::singleShot(cookingTime, this, [this]() {
        QMutexLocker locker(&mutex);
        available = true;

        emit orderCompleted(currentOrder->getTableId());
        qDebug() << "[CookModel] Commande" << currentOrder->getTableId() << "terminée.";
    });
}
