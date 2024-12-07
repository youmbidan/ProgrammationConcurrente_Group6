#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "DBController.h"
#include "MotionlessElementController.h"
#include "../../Models/MobilePointModel.h"
#include "../../Views/mainView.h"
#include "../../Views/CommonPointView.h"
#include <QThread>
#include <QObject>
#include <QTimer>// Pour std::thread



class MainController
{

public:
    explicit MainController(MainView &mainView);
    void startMainView();
    //void startMovementInThreads();
};

#endif // MAINCONTROLLER_H
