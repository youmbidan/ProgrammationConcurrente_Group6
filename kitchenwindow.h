#ifndef KITCHENWINDOW_H
#define KITCHENWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

class Kitchenwindow : public QWidget {
public:
    explicit Kitchenwindow(QWidget *parent = nullptr);
    void updateImagePosition(int index, int x, int y);
private:
    QLCDNumber *lcdTimer;
    QTimer *timer;
    int elapsedSeconds;
    void addImagesToScene(QGraphicsScene *scene);  // Déclaration de la fonction

    QWidget* createControlBar();
    void setupTimer();
};

#endif // KITCHENWINDOW_H
