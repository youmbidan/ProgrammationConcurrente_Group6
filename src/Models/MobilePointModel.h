#ifndef MOBILEPOINTMODEL_H
#define MOBILEPOINTMODEL_H

#include "../Observer/Observable.h"
#include <QObject>
#include <QGraphicsTextItem>


class MobilePointModel :public QObject, public Observable {
    Q_OBJECT
public:
    explicit MobilePointModel(const QString& labelText, int x = 0, int y = 0, QObject* parent = nullptr);

    MobilePointModel(int x, int y, QObject *parent);

    ~MobilePointModel() override;

    void move();

private:
    int x;
    int y;
    QGraphicsTextItem* label;
};

#endif // MOBILEPOINTMODEL_H
