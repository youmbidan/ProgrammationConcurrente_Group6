#ifndef KITCHEN_VIEW_H
#define KITCHEN_VIEW_H

#include <QApplication>
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

class KitchenView : public QWidget {
public:
    explicit KitchenView(QWidget *parent = nullptr);
    void updateImagePosition(int index, int x, int y);
private:
    QLCDNumber *lcdTimer;
    QTimer *timer;
    int elapsedSeconds;
    void addImagesToScene(QGraphicsScene *scene);  // Déclaration de la fonction

    QWidget* createControlBar();
    void setupTimer();
};

#endif // kitchenView_H
