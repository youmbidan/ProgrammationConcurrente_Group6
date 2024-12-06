// MainController.h
#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "DBController.h"
#include "MotionlessElementController.h"
#include "../../Views/mainView.h"

class MainController
{
private:
    DBController dbController;
    MotionlessElementController motionlessElementController;
    MainView mainView;

public:
    MainController(int argc, char *argv[]);
    void startMainView();
};

#endif // MAINCONTROLLER_H
