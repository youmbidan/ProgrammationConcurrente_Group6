#include "DinningRoomView.h"

#include <iostream>
#include <ostream>


DinningRoomView::DinningRoomView(QWidget *parent)
    : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Barre de contrôle
    mainLayout->addWidget(createControlBar());

    // Vue graphique
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);

    // Désactivation des interactions utilisateur avec la scène
    view->setInteractive(false);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setDragMode(QGraphicsView::NoDrag);

    // Fixation de la taille de la vue à la taille de la scène
    view->setFixedSize(1500, 800); // Remplacer 800 par la taille souhaitée

    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::SmoothPixmapTransform);
    view->setStyleSheet(R"(
    QGraphicsView {
        border: none;
        background-image: url(':/assets/planch2.jpg');
        border-radius: 15px;
    }
)");

    this->tableSize = 80;
    this->cols = 5;
    this->rows = 5;

    this->sectionWidth = (cols * tableSize) + (cols + 1) * 30;
    this->sectionHeight = (rows * tableSize) + (rows + 1) * 30;
    this->totalWidth = 2 * sectionWidth;
    this->totalHeight = sectionHeight + 50;
    scene->setSceneRect(0, 0, totalWidth, totalHeight);

    // Positionner la table de réception en haut à droite
    QPixmap receptionPixmap(":/assets/reception-table.png");
    QPixmap scaledReceptionPixmap = receptionPixmap.scaled(120, 80, Qt::KeepAspectRatio);
    int receptionX = totalWidth - scaledReceptionPixmap.width() - 5;
    int receptionY = 5;

    QGraphicsPixmapItem *receptionItem = scene->addPixmap(scaledReceptionPixmap);
    receptionItem->setPos(receptionX, receptionY);
    receptionItem->setFlag(QGraphicsItem::ItemIsMovable, false);
    receptionItem->setFlag(QGraphicsItem::ItemIsSelectable, false);
    receptionItem->setAcceptedMouseButtons(Qt::NoButton);

    // Ajouter l'image du chef
    QPixmap chefPixmap(":/assets/tapis.png");
    int chefWidth = 100;
    int chefHeight = 200;
    QPixmap scaledChefPixmap = chefPixmap.scaled(chefWidth, chefHeight, Qt::KeepAspectRatio);
    QGraphicsPixmapItem *chefItem = scene->addPixmap(scaledChefPixmap);
    chefItem->setPos(0, -2);

    // Ajouter l'image du maître d'hôtel
    QPixmap maîtrePixmap(":/assets/maitre.png");
    int maîtreWidth = 100;
    int maîtreHeight = 200;
    QPixmap scaledMaîtrePixmap = maîtrePixmap.scaled(maîtreWidth, maîtreHeight, Qt::KeepAspectRatio);
    QGraphicsPixmapItem *maîtreItem = scene->addPixmap(scaledMaîtrePixmap);
    maîtreItem->setPos(chefWidth + 10, -2);

    mainLayout->addWidget(view);

    // Chargement des images des tables
    QPixmap table2Pixmap(":/assets/table2.png");
    QPixmap table4Pixmap(":/assets/table4.png");
    QPixmap table6Pixmap(":/assets/table6.png");
    QPixmap table8Pixmap(":/assets/table8.png");


    setLayout(mainLayout);
}

QWidget* DinningRoomView::createControlBar() {
    QWidget *controlBar = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(controlBar);

    auto createButton = [](const QString &label, const QString &tooltip) -> QPushButton * {
        QPushButton *btn = new QPushButton(label);
        btn->setFixedSize(100, 50);
        btn->setToolTip(tooltip);
        btn->setStyleSheet(R"(
            QPushButton {
                background-color: #4CAF50;
                color: white;
                border-radius: 5px;
            }
            QPushButton:hover {
                background-color: #45a049;
            }
            QPushButton:pressed {
                background-color: #388e3c;
            }
        )");
        return btn;
    };

    return controlBar;
}

void DinningRoomView::createTable(QPixmap pixmap, int x, int y) {


    QGraphicsPixmapItem *table = scene->addPixmap(pixmap.scaled(tableSize * 1, tableSize * 1, Qt::KeepAspectRatio));

    table->setFlag(QGraphicsItem::ItemIsMovable, false);
    table->setFlag(QGraphicsItem::ItemIsSelectable, false);
    table->setAcceptedMouseButtons(Qt::NoButton);  // Empêcher toute interaction avec la souris
    table->setPos(x, y);
    //std::cout << "table created at (" << x <<","<< y <<")"<< std::endl;
}

void DinningRoomView::addTableTwoToDinningRoomScene(int x, int y) {
    QPixmap table2Pixmap(":/assets/table2.png");
    createTable(table2Pixmap, x, y);

}

void DinningRoomView::addTableFourToDinningRoomScene(int x, int y) {
    QPixmap table4Pixmap(":/assets/table4.png");
    createTable(table4Pixmap, x, y);

}

void DinningRoomView::addTableSixToDinningRoomScene(int x, int y) {
    QPixmap table6Pixmap(":/assets/table6.png");
    createTable(table6Pixmap, x, y);

}

void DinningRoomView::addTableHeightToDinningRoomScene(int x, int y) {
    QPixmap table8Pixmap(":/assets/table8.png");
    createTable(table8Pixmap, x, y);

}

void DinningRoomView::addCharacterToScene(QGraphicsItem *characterPoint) {
    scene->addItem(characterPoint);
}





