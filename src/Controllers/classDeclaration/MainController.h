#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "DBController.h"
#include "MotionlessElementController.h"
#include "../../Views/MainView.h"
#include "../../Views/CommonPointView.h"
#include "../../Views/SetupView/SetupView.h"

#include "CharacterElementController.h"
#include "DinningRoomController.h"
#include <QThread>
#include <QObject>
#include <QTimer>


class MainController : public QObject {
    Q_OBJECT
private:
    MainView *mainView;
    DinningRoomView *dinningRoomView;
    KitchenView *kitchenView;
    MotionlessElementController *motionlessElementController;
    CharacterElementController *characterElementController;
    DinningRoomController *dinningRoomController;
    ThreadPoolManager *threadPoolManager;

public:
    MainController(MainView& mainView);

    void startMainView();

    public slots:
        void onConfigurationValidated(int time, int clients, const QString& mode, const QString& additionalInfo);// Slot pour la validation de la configuration
};
#endif 