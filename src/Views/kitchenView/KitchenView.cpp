#include "KitchenView.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGraphicsDropShadowEffect>
#include <QtWidgets/QLabel>
#include <QPropertyAnimation>
#include <QtWidgets/QStyle>
#include <QtWidgets/QLCDNumber>
#include <QTimer>
#include <QTime>
#include <iostream>
#include "../dashboardView/Dashboard.h"


KitchenView::KitchenView(QWidget *parent)
    : QWidget(parent), elapsedSeconds(0) {

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
    view->setFixedSize(1500, 800);

    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::SmoothPixmapTransform);
    view->setStyleSheet(R"(
        QGraphicsView {
            border: none;
            background-image: url(':/assets/blanc.jpeg');
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
    QPixmap image1(":/assets/gaz.png");
    QPixmap image2(":/assets/lave.png");
    QPixmap image3(":/assets/fri.png");
    QPixmap image4(":/assets/etage.png");
    QPixmap image5(":/assets/mach.png");
    QPixmap image6(":/assets/gaz.png");
    QPixmap image7(":/assets/gaz.png");
    QPixmap image8(":/assets/gaz.png");
    QPixmap image9(":/assets/armoire.png");
    QPixmap image10(":/assets/serviette.png");

    // Ajouter les images à la scène avec des positions adaptées
    QGraphicsPixmapItem *item1 = scene->addPixmap(image1.scaled(200, 200, Qt::KeepAspectRatio));
    item1->setPos(10, 470); // Position (coin supérieur gauche)

    QGraphicsPixmapItem *item2 = scene->addPixmap(image2.scaled(150, 150, Qt::KeepAspectRatio));
    item2->setPos(1000, 500); // Position (centre de la scène)

    QGraphicsPixmapItem *item3 = scene->addPixmap(image3.scaled(400, 400, Qt::KeepAspectRatio));
    item3->setPos(800, -90); // Position (coin inférieur droit)

    QGraphicsPixmapItem *item4 = scene->addPixmap(image4.scaled(150, 150, Qt::KeepAspectRatio));
    item4->setPos(2, 5); // Position (coin inférieur droit)

    QGraphicsPixmapItem *item5 = scene->addPixmap(image5.scaled(120, 120, Qt::KeepAspectRatio));
    item5->setPos(900, 500); // Position (coin inférieur droit)
    QGraphicsPixmapItem *item6 = scene->addPixmap(image6.scaled(200, 200, Qt::KeepAspectRatio));
    item6->setPos(200, 470); // Position (coin inférieur droit)

    QGraphicsPixmapItem *item7 = scene->addPixmap(image7.scaled(200, 200, Qt::KeepAspectRatio));
    item7->setPos(400, 470); // Position (coin inférieur droit)
    QGraphicsPixmapItem *item8 = scene->addPixmap(image8.scaled(200, 200, Qt::KeepAspectRatio));
    item8->setPos(600, 470); // Position (coin inférieur droit)
    QGraphicsPixmapItem *item9 = scene->addPixmap(image9.scaled(300, 300, Qt::KeepAspectRatio));
    item9->setPos(500, -90); // Position (coin inférieur droit)

    QGraphicsPixmapItem *item10 = scene->addPixmap(image10.scaled(120, 120, Qt::KeepAspectRatio));
    item10->setPos(300, -10); // Position (coin inférieur droit)
    

    // Ajouter une colonne pour la séparation
    int columnX = 1200; // Position en X pour la colonne
    int columnWidth = 300; // Largeur de la colonne

    // Partie supérieure (Chambre froide)
    QGraphicsRectItem *coldRoom = new QGraphicsRectItem(columnX, 0, columnWidth, 400); // Rectangle supérieur
    coldRoom->setBrush(QBrush(QColor(0, 0, 0, 100))); // Couleur semi-transparente
    coldRoom->setPen(Qt::NoPen);

    // Ajouter un effet flou
    QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect();
    blurEffect->setBlurRadius(15);
    coldRoom->setGraphicsEffect(blurEffect);
    scene->addItem(coldRoom);

    // Ajouter un texte pour la chambre froide
    QGraphicsTextItem *coldRoomText = scene->addText("Chambre froide");
    coldRoomText->setDefaultTextColor(Qt::white);
    coldRoomText->setFont(QFont("Arial", 20, QFont::Bold));
    coldRoomText->setPos(columnX + 50, 150); // Position centré verticalement dans la zone

    // Partie inférieure (Réserve)
    QGraphicsRectItem *reserve = new QGraphicsRectItem(columnX, 400, columnWidth, 400); // Rectangle inférieur
    reserve->setBrush(QBrush(QColor(0, 0, 0, 50))); // Couleur semi-transparente
    reserve->setPen(Qt::NoPen);

    // Ajouter un effet flou
    QGraphicsBlurEffect *reserveBlurEffect = new QGraphicsBlurEffect();
    reserveBlurEffect->setBlurRadius(10);
    reserve->setGraphicsEffect(reserveBlurEffect);
    std::cout << "test modif" << std::endl;
    scene->addItem(reserve);

    // Ajouter un texte pour la réserve
    QGraphicsTextItem *reserveText = scene->addText("Réserve");
    reserveText->setDefaultTextColor(Qt::white);
    reserveText->setFont(QFont("Arial", 20, QFont::Bold));
    reserveText->setPos(columnX + 90, 550); // Position centré verticalement dans la zone
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

void KitchenView::addCharacterToScene(QGraphicsItem *characterPoint) {
    scene->addItem(characterPoint);
}