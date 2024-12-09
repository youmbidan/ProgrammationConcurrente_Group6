#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "DBController.h"
#include "MotionlessElementController.h"
#include "../../Views/MainView.h"
#include "../../Views/CommonPointView.h"
#include <QThread>
#include <QObject>
#include <QTimer>// Pour std::thread

#include "CharacterElementController.h"


class MainController
{

    MainView *mainView;
    DinningRoomView *dinningRoomView;
    KitchenView *kitchenView;
    MotionlessElementController *motionlessElementController;
    CharacterElementController *characterElementController;
public:
    explicit MainController(MainView &mainView);
    void startMainView();
};

#endif // MAINCONTROLLER_H
