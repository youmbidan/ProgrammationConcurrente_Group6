#ifndef COMMONPOINTVIEW_H
#define COMMONPOINTVIEW_H

#include <QGraphicsPixmapItem>
#include <QString>
#include "../Observer/Observer.h"
#include "../Structs/PointStruct.h"

class CommonPointView : public QObject, public QGraphicsPixmapItem, public Observer {
    Q_OBJECT
public:
    ~CommonPointView() override;

    CommonPointView(const QString &labelText, int initialX, int initialY,
                    const QString& imagePath, QGraphicsItem *parent = nullptr);

    void update(const std::any& data) override;
    int getX() const;
    int getY() const;

private:
    int x{};
    int y{};
    QString imagePath; // Chemin de l'image à afficher
    QGraphicsTextItem *label;
};

#endif //COMMONPOINTVIEW_H
