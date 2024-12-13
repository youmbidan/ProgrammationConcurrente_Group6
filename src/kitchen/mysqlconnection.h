#ifndef MYSQLCONNECTION_H
#define MYSQLCONNECTION_H

#include "QSqlDatabase"
#include "QSqlQuery"

static bool connectionbd(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("masterchef");
    db.setUserName("root");
    db.setPassword("");

    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données :" << db.lastError().text();
        return false;
    }

    qDebug() << "Connexion réussie à la base de données.";
    db.close(); // Bonne pratique de fermer la base si elle n'est plus nécessaire
    return true;


}

#endif // MYSQLCONNECTION_H
