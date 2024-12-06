#include "KitchenView.h"


KitchenView::KitchenView(QWidget *parent)
    : QWidget(parent), elapsedSeconds(0) {

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Barre de contrôle
    mainLayout->addWidget(createControlBar());

    // Vue graphique
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);

    // Désactivation des interactions utilisateur avec la scène
    view->setInteractive(false);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setDragMode(QGraphicsView::NoDrag);

    // Fixation de la taille de la vue à la taille de la scène
    view->setFixedSize(1500, 800);

    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::SmoothPixmapTransform);
    view->setStyleSheet(R"(
        QGraphicsView {
            border: none;
            background-image: url(':/assets/sol.jpeg');
            border-radius: 15px;
        }
    )");

    // Définir la taille de la scène
    scene->setSceneRect(0, 0, 1500, 800);

    // Ajouter des images à la scène
    addImagesToScene(scene);

    // Ajouter la vue graphique à la mise en page principale
    mainLayout->addWidget(view);
}

void KitchenView::addImagesToScene(QGraphicsScene *scene) {
    // Charger les images
    QPixmap image1(":/assets/kitchen.png");
    QPixmap image2(":/assets/kitchen-shelves.png");
    QPixmap image3(":/assets/machine.png");
    QPixmap image4(":/assets/counter.png");

    // Ajouter les images à la scène avec des positions adaptées
    QGraphicsPixmapItem *item1 = scene->addPixmap(image1.scaled(200, 200, Qt::KeepAspectRatio));
    item1->setPos(10, 440);  // Position (coin supérieur gauche)

    QGraphicsPixmapItem *item2 = scene->addPixmap(image2.scaled(100, 100, Qt::KeepAspectRatio));
    item2->setPos(1300, 10);  // Position (centre de la scène)

    QGraphicsPixmapItem *item3 = scene->addPixmap(image3.scaled(100, 100, Qt::KeepAspectRatio));
    item3->setPos(1200, 10);  // Position (coin inférieur droit)

    QGraphicsPixmapItem *item4 = scene->addPixmap(image4.scaled(100, 100, Qt::KeepAspectRatio));
    item4->setPos(5, 10);  // Position (coin inférieur droit)
}

QWidget* KitchenView::createControlBar() {
    QWidget *controlBar = new QWidget();
    //QHBoxLayout *layout = new QHBoxLayout(controlBar);

    auto createButton = [](const QStyle::StandardPixmap iconType, const QString &tooltip) -> QPushButton * {
        QPushButton *btn = new QPushButton();
        btn->setIcon(QApplication::style()->standardIcon(iconType));
        btn->setIconSize(QSize(40, 40));
        btn->setFixedSize(70, 70);
        btn->setToolTip(tooltip);
        btn->setStyleSheet(R"(
            QPushButton {
                background-color: #FF5722;
                border: none;
                color: white;
                border-radius: 35px;
            }
            QPushButton:hover {
                background-color: #f44336;
                transform: scale(1.1);
            }
            QPushButton:pressed {
                background-color: #e64a19;
            }
        )");
        return btn;
    };

    return controlBar;
}
