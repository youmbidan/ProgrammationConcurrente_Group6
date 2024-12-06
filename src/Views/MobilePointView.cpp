//
// Created by seand on 12/4/2024.
//

#include "MobilePointView.h"
#include <any>
#include <iostream>
#include <qbrush.h>
#include <qfont.h>

#include "../Structs/PointStruct.h"


MobilePointView::MobilePointView(const QString& labelText, const int initialX, const int initialY, QGraphicsItem* parent)
    : QGraphicsEllipseItem(0, 0, 10, 10, parent), x(initialX), y(initialY)
{
    setBrush(QBrush(Qt::black));
    setPos(x, y);

    this->label = new QGraphicsTextItem(labelText, this);
    label->setDefaultTextColor(Qt::blue);
    label->setFont(QFont("Arial", 10, QFont::Bold));
    label->setPos(-label->boundingRect().width() / 2, -label->boundingRect().height() - 5);
}

void MobilePointView::update(const std::any& data) {

    PointStruct coord = std::any_cast<PointStruct>(data);

    x = coord.x;
    y = coord.y;

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


