#include "MobilePointModel.h"
#include <QTimer>
#include <unordered_map>
#include <any>
#include <iostream>

#include "../Structs/PointStruct.h"

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
            PointStruct data = {x, y};
            notify(data);

            std::cout << "Coordinates updated: x = " << x << ", y = " << y << std::endl;
        } else {
            timer->stop();
            timer->deleteLater();
            std::cout << "Movement finished." << std::endl;
        }
    });
    timer->start(50);
}
