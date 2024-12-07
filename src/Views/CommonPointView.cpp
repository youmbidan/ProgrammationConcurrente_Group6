//
// Created by seand on 12/4/2024.
//

#include "CommonPointView.h"
#include <any>
#include <iostream>
#include <qbrush.h>
#include <qfont.h>

#include "../Structs/PointStruct.h"


CommonPointView::CommonPointView(const QString& labelText, const int initialX, const int initialY, const int weight, QGraphicsItem* parent)
    : QGraphicsEllipseItem(0, 0, 5*weight, 5*weight, parent), x(initialX), y(initialY)
{
    setBrush(QBrush(Qt::black));
    setPos(x, y);

    this->label = new QGraphicsTextItem(labelText, this);
    label->setDefaultTextColor(Qt::blue);
    label->setFont(QFont("Arial", 10, QFont::Bold));
    label->setPos(-label->boundingRect().width() / 2, -label->boundingRect().height() - 5);
}

void CommonPointView::update(const std::any& data) {

    PointStruct coord = std::any_cast<PointStruct>(data);

    x = coord.x;
    y = coord.y;

    std::cout << "updating: newX = " << x << " newY = " << x << std::endl;

    setPos(x, x);
    //emit positionUpdated();  // Émet un signal

}

CommonPointView::~CommonPointView() = default;

int CommonPointView::getX() const {
    return x;
}

int CommonPointView::getY() const {
    return y;
}


void CommonPointView::setSize(int width, int height) {
    setRect(0, 0, width, height);
}



