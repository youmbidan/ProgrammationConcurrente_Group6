//
// Created by franck on 12/2/24.
//
#include "../classDeclaration/MobileElementModel.h"

#include <QApplication>

void MobileElementModel::move(PointStruct finalCoords) {
    // Attacher l'objet au thread principal si nécessaire
    QMetaObject::invokeMethod(this, [this, finalCoords]() {

    auto* timer = new QTimer(this); // Créé dans le thread principal
    double finalX = finalCoords.x;
    double finalY = finalCoords.y;

    connect(timer, &QTimer::timeout, [this, timer, finalX, finalY]() {
        // Incrémentation ou décrémentation des abscisses et ordonnées
        if (abscice < finalX) {
            abscice++;
        } else if (abscice > finalX) {
            abscice--;
        }

        if (intercept < finalY) {
            intercept++;
        } else if (intercept > finalY) {
            intercept--;
        }

        // Création de la structure de données pour la mise à jour
        PointStruct data = {abscice, intercept};
        notify(data); // Mise à jour des observateurs, par exemple, CommonPointView

        // Si les coordonnées sont atteintes ou dépassées, on arrête le timer
        if ((abscice >= finalX && abscice <= finalX) && (intercept >= finalY && intercept <= finalY)) {
            timer->stop();
            timer->deleteLater();
        }
    });

    timer->start(7);
    }, Qt::QueuedConnection);

}


void MobileElementModel::backToInitialPosition() {
    std::cout << "coordonées initiales" << initialAbscice << std::endl;
    move({initialAbscice, initialIntercept});
}
