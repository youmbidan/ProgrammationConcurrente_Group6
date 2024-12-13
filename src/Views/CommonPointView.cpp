#include "CommonPointView.h"
#include <any>
#include <iostream>
#include <QBrush>
#include <QFont>
#include <QPixmap>
#include "../Structs/PointStruct.h"

CommonPointView::CommonPointView(const QString& labelText, const int initialX, const int initialY,
                                 const QString& imagePath, QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent), x(initialX), y(initialY), imagePath(imagePath)
{
    // Charger l'image depuis le chemin d'accès
    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        std::cerr << "Error: Unable to load image from " << imagePath.toStdString() << std::endl;
        return;
    }

    // Définir l'image comme contenu graphique
    setPixmap(pixmap);
    setPos(x, y);

    // Ajouter une étiquette
    label = new QGraphicsTextItem(labelText, this);
    label->setDefaultTextColor(Qt::blue);
    label->setFont(QFont("Arial", 10, QFont::Bold));
    label->setPos(-label->boundingRect().width() / 2, -label->boundingRect().height() - 5);
}

void CommonPointView::update(const std::any& data) {
    try {
        // Assurez-vous que 'data' contient un PointStruct
        auto coord = std::any_cast<PointStruct>(data);

        // Mise à jour des coordonnées graphiques
        setPos(coord.x, coord.y);

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
