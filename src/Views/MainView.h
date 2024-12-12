#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QtWidgets/QApplication>
#include <QMainWindow>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QPropertyAnimation>
#include <QStyle>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include "kitchenView/KitchenView.h"
#include "dinningRoomView/DinningRoomView.h"
#include "MobilePointView.h"
#include "../kitchen/ChefModel.h"

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget* parent = nullptr);
    void start();  // Méthode pour afficher la fenêtre et commencer le comptage du temps

private:
    ChefModel* chefModel;
};

#endif // MAINVIEW_H
