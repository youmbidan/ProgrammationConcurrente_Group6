#include "MobilePointModel.h"
#include <QTimer>
#include <unordered_map>
#include <any>
#include <iostream>

MobilePointModel::MobilePointModel(int x, int y, QObject* parent)
    : QObject(parent), x(x), y(y) {}

MobilePointModel::~MobilePointModel() = default;

void MobilePointModel::move() {
    QTimer* timer = new QTimer(this);  // Associe le timer au modèle pour une gestion automatique
    connect(timer, &QTimer::timeout, [this, timer]() {
        if (x <

        500) {
            x++;
            y++;
            std::unordered_map<std::string, std::any> data;
            data["x"] = x;
            data["y"] = y;
            notify(data);

            std::cout << "Coordinates updated: x = " << x << ", y = " << y << std::endl;
        } else {
            timer->stop();
            timer->deleteLater();
            emit movementFinished();  // Émet un signal pour indiquer que le mouvement est terminé
            std::cout << "Movement finished." << std::endl;
        }
    });
    timer->start(50);  // Déclenche le timer toutes les 100 ms
}
