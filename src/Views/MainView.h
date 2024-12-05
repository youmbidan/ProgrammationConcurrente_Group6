#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "MobilePointView.h"

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget* parent = nullptr, MobilePointView* mobilePoint = nullptr);  // Accepte un pointeur vers MobilePoint
    //void refreshView();
    void start();
    // public slots:
    //     void onPositionUpdated();
private:
    QGraphicsView* graphicsView;
    QGraphicsScene* graphicsScene;
    MobilePointView* mobilePoint;  // Utilisation d'un pointeur pour mobilePoint
};

#endif // MAINVIEW_H
