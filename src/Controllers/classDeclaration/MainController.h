#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "DBController.h"
#include "MotionlessElementController.h"
#include "../../Views/MainView.h"
#include "../../Views/SetupView/SetupView.h"

#include "CharacterElementController.h"
#include "DinningRoomController.h"
#include <QThread>
#include <QObject>
#include <QTimer>

#include "KitchenController.h"
#include "SharedOrdersQueue.h"


class MainController : public QObject {
    Q_OBJECT
    MainView *mainView;
    DinningRoomView *dinningRoomView;
    KitchenView *kitchenView;
    MotionlessElementController *motionlessElementController;
    CharacterElementController *characterElementController;
    DinningRoomController *dinningRoomController;
    KitchenController *kitchenController;
    ThreadPoolManager *threadPoolManager;
    std::queue<Order*> ordersOnCounterQueue;

    std::queue<Order*> ordersReadyOnCounterQueue;
    SharedOrdersQueue sharedOrdersQueue;

public:
    MainController(MainView& mainView);

    void startMainView();

    void startOrderProcessing();

    // void connectControllers();

    public slots:
        void onConfigurationValidated(int time, int clients, const QString& mode, const QString& additionalInfo);// Slot pour la validation de la configuration
};
#endif 