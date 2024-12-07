//
// Created by franck on 12/2/24.
//
#include "../classDeclaration/MobileElementModel.h"

void MobileElementModel::move(double finalX, double finalY) {
    auto* timer = new QTimer(this);  // Associe le timer au modèle pour une gestion automatique
    connect(timer, &QTimer::timeout, [this, timer, finalX, finalY]() {
        if (abscice <

        finalX) {
            abscice++;
            PointStruct data = {abscice, intercept};
            notify(data);

        } else if (intercept <

        finalY) {
            intercept++;
            PointStruct data = {abscice, intercept};
            notify(data);

        } else  {
            std::cout << "Coordinates updated: x = " << abscice << ", y = " << intercept << std::endl;
            timer->stop();
            // timer->deleteLater();
            std::cout << "Movement finished." << std::endl;
        }
    });
    timer->start(50);

    //ressource deallocation for our QTimer
    delete timer;
}