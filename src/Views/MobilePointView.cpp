//
// Created by seand on 12/4/2024.
//

#include "MobilePointView.h"
#include <any>
#include <iostream>
#include <qbrush.h>
#include <unordered_map>


MobilePointView::MobilePointView(const int initialX, const int initialY, QGraphicsItem* parent)
    : QGraphicsEllipseItem(0, 0, 10, 10, parent), x(initialX), y(initialY)
{
    setBrush(QBrush(Qt::black));
    setPos(x, y);
}

void MobilePointView::update(const std::unordered_map<std::string, auto>& data) {

    x = data.at("x");  // Mettre à jour x
    y = data.at("y");  // Mettre à jour y
    std::cout << "updating: newX = " << x << " newY = " << x << std::endl;

    setPos(x, x);
    //emit positionUpdated();  // Émet un signal


    std::cout << "Scene pos: (" << this->pos().x() << ", " << this->pos().y() << ")" << std::endl;


    // Afficher les nouvelles coordonnées
    std::cout << "MobilePoint updated !!!!" << std::endl;
}

MobilePointView::~MobilePointView() = default;

int MobilePointView::getX() const {
    return x;
}

int MobilePointView::getY() const {
    return y;
}


