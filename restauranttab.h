#ifndef RESTAURANTTAB_H
#define RESTAURANTTAB_H

#include "QtWidgets/qwidget.h"


class RestaurantTab : public QWidget {
    Q_OBJECT

public:
    explicit RestaurantTab(QWidget *parent = nullptr);


private:
    QWidget *createControlBar();
};

#endif // RESTAURANTTAB_H
