#include "../classDeclaration/SocketController.h"
#include <QDebug>

SocketController::SocketController(QObject *parent)
    : QObject(parent), server(nullptr), clientSocket(nullptr) {}

void SocketController::startServer(int port) {
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &SocketController::onNewConnection);

    if (!server->listen(QHostAddress::Any, port)) {
        qCritical() << "Server could not start!";
    } else {
        qDebug() << "Server started on port" << port;
    }
}

void SocketController::connectToServer(const QString &host, int port) {
    clientSocket = new QTcpSocket(this);
    clientSocket->connectToHost(host, port);

    connect(clientSocket, &QTcpSocket::readyRead, this, &SocketController::onReadyRead);
    if (clientSocket->waitForConnected(3000)) {
        qDebug() << "Connected to server";
    } else {
        qCritical() << "Connection to server failed!";
    }
}

void SocketController::sendOrder(const Order &order) {
    if (clientSocket) {
        QString data = order.serialize();
        clientSocket->write(data.toUtf8());
    } else {
        qCritical() << "No client socket to send order!";
    }
}

void SocketController::onNewConnection() {
    clientSocket = server->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &SocketController::onReadyRead);
    qDebug() << "New client connected";
}

void SocketController::onReadyRead() {
    if (clientSocket) {
        QString data = QString::fromUtf8(clientSocket->readAll());
        Order order = Order::deserialize(data);
        emit orderReceived(order);
    }
}

