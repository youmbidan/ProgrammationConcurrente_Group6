#ifndef RESTAURANTTAB_H
#define RESTAURANTTAB_H

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
    void addTableTwoToDinningRoomScene(int x, int y);
    void addTableFourToDinningRoomScene(int x, int y);
    void addTableSixToDinningRoomScene(int x, int y);
    void addTableHeightToDinningRoomScene(int x, int y);


private:
    QWidget *createControlBar();
    QGraphicsScene *scene;
    QGraphicsView *view;

    /**
    * @param pixmap
    * @param x
    * @param y
    */
    void createTable(QPixmap pixmap, int x, int y);

    int tableSize;
    int cols;
    int rows;

    int sectionWidth;
    int sectionHeight;
    int totalWidth;
    int totalHeight;


};

#endif // RESTAURANTTAB_H
