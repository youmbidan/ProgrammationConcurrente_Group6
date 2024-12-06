//
// Created by seand on 12/4/2024.
//

#ifndef MOBILEPOINTVIEW_H
#define MOBILEPOINTVIEW_H

#include <QGraphicsEllipseItem>
#include "../Observer/Observer.h"
#include "../Structs/PointStruct.h"



class MobilePointView : public QObject, public QGraphicsEllipseItem, public Observer {
    Q_OBJECT
public:
    ~MobilePointView() override;

    MobilePointView(const QString &labelText, int initialX, int initialY);

    MobilePointView(const QString &labelText, int initialX, int initialY, QGraphicsItem *parent);

    void update(const std::any& data) override;
    int getX() const;
    int getY() const;
    // signals:
    // void positionUpdated();

private:
    int x{};
    int y{};
    QGraphicsTextItem *label;
};



#endif //MOBILEPOINT_H
