#ifndef DINNING_ROOM_H
#define DINNING_ROOM_H

#include "QWidget"
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QPushButton>


class DinningRoomView : public QWidget {
    Q_OBJECT

public:
    explicit DinningRoomView(QWidget *parent = nullptr);


private:
    QWidget *createControlBar();
};

#endif // RESTAURANTTAB_H
