//
// Created by seand on 12/4/2024.
//

#include "CommonPointView.h"
#include <any>
#include <iostream>
#include <qbrush.h>
#include <qfont.h>

#include "../Structs/PointStruct.h"


CommonPointView::CommonPointView(const QString& labelText, const int initialX, const int initialY, QGraphicsItem* parent, const int weight)
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
    try {
        // Assurez-vous que 'data' contient un PointStruct
        auto coord = std::any_cast<PointStruct>(data);

        // Utilisation directe des types corrects de PointStruct
        int newX = static_cast<int>(coord.x);
        int newY = static_cast<int>(coord.y);


        // Mise à jour des coordonnées graphiques
            setPos(newX, newY);

    } catch (const std::bad_any_cast& e) {
        std::cerr << "Error in CommonPointView::update: " << e.what() << std::endl;
    }
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



