#include "restauranttab.h"
#include <QtWidgets/QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPushButton>

RestaurantTab::RestaurantTab(QWidget *parent)
    : QWidget(parent) {
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
    view->setFixedSize(1500, 800); // Remplacer 800 par la taille souhaitée

    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::SmoothPixmapTransform);
    view->setStyleSheet(R"(
    QGraphicsView {
        border: none;
        background-image: url(':/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/Assets/planch2.jpg');
        border-radius: 15px;
    }
)");

    // Calcul de la taille de la scène
    const int tableSize = 80;
    const int cols = 5;
    const int rows = 5;

    const int sectionWidth = (cols * tableSize) + (cols + 1) * 30; // Diminué l'espacement horizontal
    const int sectionHeight = (rows * tableSize) + (rows + 1) * 30; // Diminué l'espacement vertical
    const int totalWidth = 2 * sectionWidth;
    const int totalHeight = sectionHeight + 50; // Ajout d'un espace supplémentaire en bas pour ajuster

    scene->setSceneRect(0, 0, totalWidth, totalHeight);

    // Positionner la table de réception en haut à droite
    QPixmap receptionPixmap(":/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/Assets/reception-table.png");
    QPixmap scaledReceptionPixmap = receptionPixmap.scaled(120, 80, Qt::KeepAspectRatio);
    int receptionX = totalWidth - scaledReceptionPixmap.width() - 5;
    int receptionY = 5;

    QGraphicsPixmapItem *receptionItem = scene->addPixmap(scaledReceptionPixmap);
    receptionItem->setPos(receptionX, receptionY);
    receptionItem->setFlag(QGraphicsItem::ItemIsMovable, false);
    receptionItem->setFlag(QGraphicsItem::ItemIsSelectable, false);
    receptionItem->setAcceptedMouseButtons(Qt::NoButton);

    // Ajouter l'image du chef
    QPixmap chefPixmap(":/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/Assets/tapis.png");
    int chefWidth = 100;
    int chefHeight = 200;
    QPixmap scaledChefPixmap = chefPixmap.scaled(chefWidth, chefHeight, Qt::KeepAspectRatio);
    QGraphicsPixmapItem *chefItem = scene->addPixmap(scaledChefPixmap);
    chefItem->setPos(0, -2);

    // Ajouter l'image du maître d'hôtel
    QPixmap maîtrePixmap(":/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/Assets/maitre.png");
    int maîtreWidth = 100;
    int maîtreHeight = 200;
    QPixmap scaledMaîtrePixmap = maîtrePixmap.scaled(maîtreWidth, maîtreHeight, Qt::KeepAspectRatio);
    QGraphicsPixmapItem *maîtreItem = scene->addPixmap(scaledMaîtrePixmap);
    maîtreItem->setPos(chefWidth + 10, -2);

    mainLayout->addWidget(view);

    // Chargement des images des tables
    QPixmap table2Pixmap(":/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/Assets/table2.png");
    QPixmap table4Pixmap(":/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/Assets/table4.png");
    QPixmap table6Pixmap(":/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/Assets/table6.png");
    QPixmap table8Pixmap(":/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/Assets/table8.png");

    const int spacing = 30;  // Espacement entre les tables diminué
    const int newSpacingX = (sectionWidth - (cols * tableSize)) / (cols + 1);
    const int newSpacingY = (sectionHeight - (rows * tableSize)) / (rows + 1);
    const int chefOffset = chefHeight + 10; // Diminué l'espacement pour ajuster

    auto addTable = [&](QPixmap pixmap, int row, int col, int xOffset, double scale = 1.0) {
        int x = xOffset + col * (tableSize + newSpacingX);
        int y = chefOffset + row * (tableSize + newSpacingY);
        QGraphicsPixmapItem *table = scene->addPixmap(pixmap.scaled(tableSize * scale, tableSize * scale, Qt::KeepAspectRatio));

        table->setFlag(QGraphicsItem::ItemIsMovable, false);
        table->setFlag(QGraphicsItem::ItemIsSelectable, false);
        table->setAcceptedMouseButtons(Qt::NoButton);  // Empêcher toute interaction avec la souris

        table->setPos(x, y);
    };

    auto arrangeSection = [&](int xOffset, int tableCountStart, int tableCountEnd) {
        int row = 0, col = 0;
        for (int i = tableCountStart; i < tableCountEnd; ++i) {
            if (i < tableCountStart + 5) {
                addTable(table2Pixmap, row, col, xOffset);
            } else if (i < tableCountStart + 10) {
                addTable(table4Pixmap, row, col, xOffset, 1.1);
            } else if (i < tableCountStart + 12) {
                addTable(table6Pixmap, row, col, xOffset, 1.2);
            } else {
                addTable(table8Pixmap, row, col, xOffset, 1.3);
            }

            if (++col >= cols) {
                col = 0;
                row++;
            }
        }
    };

    arrangeSection(0, 0, 15);
    arrangeSection(sectionWidth, 15, 30);

    setLayout(mainLayout);
}

QWidget* RestaurantTab::createControlBar() {
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

