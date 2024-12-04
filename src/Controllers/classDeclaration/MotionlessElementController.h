//
// Created by franck on 12/2/24.
//

#ifndef MOTIONLESSELEMENTCONTROLLER_H
#define MOTIONLESSELEMENTCONTROLLER_H
#include "../../Models/kitchenModels/classDeclaration/DirtyDishesStorage.h"
#include "../../Models/kitchenModels/classDeclaration/WashingMachine.h"
using namespace std;

/**
 * @class MotionlessElementController
 */
class MotionlessElementController {
public:

    MotionlessElementController();


    /**
     * @brief
     *
     * @param dirty_dishes_storage
     * @param washing_machine
     */
    MotionlessElementController(const DirtyDishesStorage &dirty_dishes_storage, const WashingMachine &washing_machine)
        : dirty_dishes_storage_(dirty_dishes_storage),
          washing_machine_(washing_machine) {
    }

    void createAllTable();
    void createKitchenElements();

private:
    DirtyDishesStorage dirty_dishes_storage_;
    WashingMachine washing_machine_;

};
#endif //MOTIONLESSELEMENTCONTROLLER_H
