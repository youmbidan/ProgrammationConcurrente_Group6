#ifndef kitchenView_H
#define kitchenView_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QTimer>

class kitchenView : public QWidget {
public:
    explicit kitchenView(QWidget *parent = nullptr);
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
