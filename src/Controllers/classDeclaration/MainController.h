#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "DBController.h"
#include "MotionlessElementController.h"
#include "../../Models/MobilePointModel.h"
#include "../../Views/mainView.h"
#include "../../Views/MobilePointView.h"
#include "../../Views/SetupView/SetupView.h"
#include <QThread>
#include <QObject>
#include <QTimer>// Pour std::thread


class MainController : public QObject {
    Q_OBJECT

public:
    MainController(MainView& mainView);

    void startMainView();

public slots:
    void onConfigurationValidated(int time, int clients, const QString& mode, const QString& additionalInfo); // Slot pour la validation de la configuration

private:
    MainView& m_mainView;
};
#endif 