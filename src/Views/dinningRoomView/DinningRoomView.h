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

#include "../CommonPointView.h"


class DinningRoomView : public QWidget {
    

public:
    explicit DinningRoomView(QWidget *parent = nullptr);
    void addTableTwoToDinningRoomScene(int x, int y);
    void addTableFourToDinningRoomScene(int x, int y);
    void addTableSixToDinningRoomScene(int x, int y);
    void addTableHeightToDinningRoomScene(int x, int y);

    void addCharacterToScene(QGraphicsItem *characterPoint);

    void addClientsToScene(QGraphicsItem *clientGroupPoint);

private:
    QWidget *createControlBar();
    QGraphicsScene *scene;
    QGraphicsView *view;

    /**
    * @param pixmap
    * @param x
    * @param y
    *
    * @brief  core front-end function for create a new table graphic element
    * and add it to scene
    *
    * used by all "addTable_____ToDinningRoomScene" functions
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
