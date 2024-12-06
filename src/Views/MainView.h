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
    explicit MainView(QWidget* parent = nullptr);
    //void refreshView();
    void start();
    void addToScene(QGraphicsEllipseItem* item);
    // public slots:
    //     void onPositionUpdated();
private:
    QGraphicsView* graphicsView;
    QGraphicsScene* graphicsScene;
};

#endif // MAINVIEW_H
