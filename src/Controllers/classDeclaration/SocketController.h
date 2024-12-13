#ifndef SOCKETCONTROLLER_H
#define SOCKETCONTROLLER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include "Order.h"

class SocketController : public QObject {
    Q_OBJECT

public:
    explicit SocketController(QObject *parent = nullptr);

    // Fonction pour démarrer le serveur
    void startServer(int port);

    // Fonction pour se connecter en tant que client
    void connectToServer(const QString &host, int port);

    // Fonction pour envoyer une commande
    void sendOrder(const Order &order);

signals:
    void orderReceived(const Order &order);

private slots:
    void onNewConnection();
    void onReadyRead();

private:
    QTcpServer *server;
    QTcpSocket *clientSocket;
};

#endif // SOCKETCONTROLLER_H
