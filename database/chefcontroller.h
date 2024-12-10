#ifndef CHEFCONTROLLER_H
#define CHEFCONTROLLER_H

#include <QObject>
#include "ChefModel.h"

class ChefController : public QObject {
    Q_OBJECT

public:
    explicit ChefController(ChefModel* chefModel);
    ChefModel* getChefModel() const;
    void simulateIncomingOrder();

private:
    ChefModel* chefModel;
    int nextOrderId;
};

#endif // CHEFCONTROLLER_H
