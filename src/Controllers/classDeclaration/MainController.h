#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "DBController.h"
#include "MotionlessElementController.h"
#include "../../Views/MainView.h"
#include "../../Views/SetupView/SetupView.h"

#include "CharacterElementController.h"
#include "DinningRoomController.h"


class MainController : public QObject {
    Q_OBJECT

private:
        // Voici les instances des controlleurs qui seron utilisées tout au long de l'exécution du programme
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
    void onConfigurationValidated(int time, int clients, const QString& mode, const QString& additionalInfo); // Slot pour la validation de la configuration
};
#endif 