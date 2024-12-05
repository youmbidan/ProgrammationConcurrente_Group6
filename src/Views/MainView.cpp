#include "mainView.h"
#include <QGraphicsEllipseItem>
#include <iostream>

MainView::MainView(QWidget* parent, MobilePointView* mobilePoint)
    : QMainWindow(parent),
      graphicsView(new QGraphicsView(this)),
      graphicsScene(new QGraphicsScene(this)),
      mobilePoint(mobilePoint)
{
    setFixedSize(500, 500);
    setWindowTitle("Main Application");

    graphicsView->setScene(graphicsScene);
    graphicsView->setRenderHint(QPainter::Antialiasing);
    graphicsView->setGeometry(0, 0, 500, 500);
    graphicsScene->setSceneRect(0, 0, 500, 500);


    if (mobilePoint) {
        graphicsScene->addItem(mobilePoint);
        // connect(mobilePoint, &MobilePoint::positionUpdated, this, &MainView::onPositionUpdated);;
        std::cout << "Mobile point added to scene " << std::endl;
    }
}

void MainView::start() {
    show();
    std::cout << "View has started." << std::endl;
}

// void MainView::refreshView() {
//     graphicsView->viewport()->update();  // Rafraîchit la vue
//     graphicsScene->update();             // Met à jour la scène
//     std::cout << "View refreshed." << std::endl;
// }

// void MainView::onPositionUpdated() {
//      refreshView();  // Appelle la méthode de rafraîchissement
//     //std::cout << "Position updated, relying on Qt's automatic refresh." << std::endl;
//
// }
