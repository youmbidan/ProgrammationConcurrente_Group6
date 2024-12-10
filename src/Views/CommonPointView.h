//
// Created by seand on 12/4/2024.
//

#ifndef COMMONPOINTVIEW_H
#define COMMONPOINTVIEW_H

#include <QGraphicsEllipseItem>
#include "../Observer/Observer.h"
#include "../Structs/PointStruct.h"



class CommonPointView : public QObject, public QGraphicsEllipseItem, public Observer {
    
public:
    ~CommonPointView() override;

    CommonPointView(const QString &labelText, int initialX, int initialY, QGraphicsItem *parent, int weight = 1);

    void update(const std::any& data) override;
    int getX() const;
    int getY() const;
    void setSize(int width, int height);

private:
    int x{};
    int y{};
    QGraphicsTextItem *label;
};



#endif //COMMONPOINTVIEW_H
