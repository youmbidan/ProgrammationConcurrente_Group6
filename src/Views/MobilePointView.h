//
// Created by seand on 12/4/2024.
//

#ifndef MOBILEPOINTVIEW_H
#define MOBILEPOINTVIEW_H

#include <QGraphicsEllipseItem>
#include "../Observer/Observer.h"


class MobilePointView : public QObject, public QGraphicsEllipseItem, public Observer {
    Q_OBJECT
public:
    MobilePointView(int initialX = 0, int initialY = 0, QGraphicsItem* parent = nullptr);

    ~MobilePointView() override;
    void update(const std::unordered_map<std::string, auto>& data) override;
    int getX() const;
    int getY() const;
    // signals:
    // void positionUpdated();

private:
    int x{};
    int y{};

};



#endif //MOBILEPOINT_H
