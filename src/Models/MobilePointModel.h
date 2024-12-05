#ifndef MOBILEPOINTMODEL_H
#define MOBILEPOINTMODEL_H

#include "../Observer/Observable.h"
#include <QObject>

class MobilePointModel : public QObject, public Observable {
    Q_OBJECT
public:
    explicit MobilePointModel(int x = 0, int y = 0, QObject* parent = nullptr);
    ~MobilePointModel() override;

    void move();

    signals:
        void movementFinished();  // Signal pour indiquer la fin du mouvement

private:
    int x;
    int y;
};

#endif // MOBILEPOINTMODEL_H
