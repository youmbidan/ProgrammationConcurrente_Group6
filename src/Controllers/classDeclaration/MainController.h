#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "DBController.h"
#include "MotionlessElementController.h"
#include "../../Views/MainView.h"
#include "../../Views/CommonPointView.h"

#include "CharacterElementController.h"
#include "DinningRoomController.h"


class MainController
{
    // Voici les instances des controlleurs qui seron utilisées tout au long de l'exécution du programme
    MainView *mainView;
    DinningRoomView *dinningRoomView;
    KitchenView *kitchenView;
    MotionlessElementController *motionlessElementController;
    CharacterElementController *characterElementController;
    DinningRoomController *dinningRoomController;
    ThreadPoolManager *threadPoolManager;

public:
    explicit MainController(MainView &mainView);
    void startMainView();
};

#endif // MAINCONTROLLER_H
