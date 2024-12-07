#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include "kitchenView/KitchenView.h"
#include "dinningRoomView/DinningRoomView.h"
#include "CommonPointView.h"

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget* parent = nullptr);
    void start();

    KitchenView* getKitchenView();
    DinningRoomView* getDinningRoomView();

private:

    KitchenView *kitchenView;
    DinningRoomView *dinningRoomView;

    QPushButton* createButton(QStyle::StandardPixmap iconType, const QString& tooltip);
    void updateTimerDisplay();

    void startTimer();
    void pauseTimer();
    void resetTimer();


    QTimer* timer;
    QLCDNumber* lcdTimer;
    bool timerRunning;
    int elapsedSeconds;
};

#endif
