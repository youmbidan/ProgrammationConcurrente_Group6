#include "CookModel.h"
#include <QTimer>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMutexLocker>

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

    if (!checkResources(order)) {
        qWarning() << "Commande" << order.id << "non terminée : Ressources insuffisantes.";
        emit orderFailed(order.id);
        return;
    }

    currentOrder = order;
    available = false;

    qDebug() << "Commande" << order.id << "assignée à un cuisinier.";
    QMetaObject::invokeMethod(this, "processOrder", Qt::QueuedConnection);
}

bool CookModel::checkResources(const Order& order) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Donald/Documents/projets_qt/database/masterchef.db");

    if (!db.open()) {
        qCritical() << "Erreur : Impossible d'ouvrir la base de données" << db.lastError().text();
        return false;
    }

    qDebug() << "Connexion à la base de données réussie.";

    for (auto it = order.recipesWithQuantities.cbegin(); it != order.recipesWithQuantities.cend(); ++it) {
        const Recipe& recipe = it.key();
        int quantity = it.value();

        // Vérification des ingrédients
        for (const QString& ingredient : recipe.getIngredients()) {
            QSqlQuery query;
            query.prepare("SELECT quantity FROM ingredients WHERE name = :name");
            query.bindValue(":name", ingredient);

            if (!query.exec() || !query.next()) {
                qWarning() << "Ingrédient non disponible :" << ingredient;
                db.close();
                return false;
            }

            int availableQuantity = query.value(0).toInt();
            if (availableQuantity < quantity) {
                qWarning() << "Stock insuffisant pour l'ingrédient :" << ingredient
                           << ". Requis:" << quantity << ", Disponible:" << availableQuantity;
                db.close();
                return false;
            }
        }

        // Vérification des ustensiles (similaire)
        //for (const QString& ustensil : recipe.getUstensils()) {
           // QSqlQuery query;
            //query.prepare("SELECT available FROM ustensils_kitchen WHERE name = :name");
            //query.bindValue(":name", ustensil);

            //if (!query.exec() || !query.next()) {
               //qWarning() << "Ustensile non disponible :" << ustensil;
                //db.close();
                //return false;
            //}

            //bool isAvailable = query.value(0).toBool();
            //if (!isAvailable) {
                //qWarning() << "Ustensile non utilisable :" << ustensil;
                //db.close();
                //return false;
            //}
        //}
    }

    db.close();
    return true;
}


void CookModel::processOrder() {
    int cookingTime = currentOrder.getTotalCookingTime() * 1000;
    qDebug() << "Temps total de la commande sera :" << cookingTime << "milli-secondes.";
    QTimer::singleShot(cookingTime, this, [this]() {
        QMutexLocker locker(&mutex);
        available = true;
        emit orderCompleted(currentOrder.id);
        qDebug() << "Commande" << currentOrder.id << "terminée.";
    });
}
