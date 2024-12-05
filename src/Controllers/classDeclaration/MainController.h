#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "DBController.h"
#include "MotionlessElementController.h"
#include "../../Models/MobilePointModel.h"
#include "../../Views/mainView.h"
#include "../../Views/MobilePointView.h"

class MainController
{
private:
    DBController dbController;
    MotionlessElementController motionlessElementController;
    MainView &mainView;
    MobilePointView &mobile_point;  // Référence à MobilePoint
    MobilePointModel* mobile_point_model;  // Pointeur vers MobilePointModel

public:
    explicit MainController(MainView &mainView, MobilePointView &mobile_point);
    void startMainView();
};

#endif // MAINCONTROLLER_H
