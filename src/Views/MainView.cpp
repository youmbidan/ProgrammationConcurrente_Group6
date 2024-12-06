#include "mainView.h"
#include <QGraphicsEllipseItem>
#include <iostream>

MainView::MainView(QWidget* parent)
    : QMainWindow(parent)
     // graphicsView(new QGraphicsView(this)),
      //graphicsScene(new QGraphicsScene(this))
{
    setWindowTitle("Gestion du Restaurant");
    resize(1024, 768);

    // graphicsView->setScene(graphicsScene);
    // graphicsView->setRenderHint(QPainter::Antialiasing);
    // graphicsView->setGeometry(0, 0, 500, 500);
    // graphicsScene->setSceneRect(0, 0, 500, 500);

    // Création du QTabWidget
    QTabWidget *tabWidget = new QTabWidget;
    tabWidget->addTab(new DinningRoomView, "Restaurant");
    tabWidget->addTab(new KitchenView, "Cuisine");

    // Création du cadre principal
    QFrame *mainFrame = new QFrame;
    mainFrame->setStyleSheet("background-color: #e0e0e0; border-radius: 10px; padding: 20px;");
    QVBoxLayout *mainLayout = new QVBoxLayout(mainFrame);

    // Barre de contrôle (header)
    QHBoxLayout *controlBar = new QHBoxLayout();

    // Création d'un bouton avec icônes Qt standard
    auto createButton = [](const QStyle::StandardPixmap iconType, const QString &tooltip) -> QPushButton *
    {
        QPushButton *btn = new QPushButton();
        btn->setIcon(QApplication::style()->standardIcon(iconType));
        btn->setIconSize(QSize(24, 24));
        btn->setFixedSize(48, 48);
        btn->setToolTip(tooltip);
        btn->setStyleSheet(R"(
            QPushButton {
                background-color: #4CAF50;
                border: none;
                color: white;
                border-radius: 24px;
                font-size: 16px;
            }
            QPushButton:hover {
                background-color: #45a049;
            }
            QPushButton:pressed {
                background-color: #3e8e41;
            }
        )");
        return btn;
    };

    // Boutons de contrôle
    QPushButton *startButton = createButton(QStyle::SP_MediaPlay, "Start");
    QPushButton *pauseButton = createButton(QStyle::SP_MediaPause, "Pause");
    QPushButton *stopButton = createButton(QStyle::SP_MediaStop, "Stop");
    QPushButton *rewindButton = createButton(QStyle::SP_MediaSeekBackward, "Rewind");
    QPushButton *forwardButton = createButton(QStyle::SP_MediaSeekForward, "Forward");
    QPushButton *application_menu = createButton(QStyle::SP_TitleBarMenuButton, "Menu"); // Icône du menu

    // LCD pour le temps écoulé
    QLCDNumber *lcdTimer = new QLCDNumber();
    lcdTimer->setDigitCount(8);
    lcdTimer->setFixedHeight(50);
    lcdTimer->setStyleSheet("border: none; color: #2c3e50; background: transparent; font-size: 18px;");

    QTime startTime = QTime::currentTime();
    QTimer *timer = new QTimer;

    // Variables pour suivre l'état du minuteur et le temps écoulé
    bool timerRunning = true;
    int elapsedSeconds = 0;

    // Mise à jour du temps affiché
    auto updateTimeDisplay = [&]() {
        QTime displayTime(0, 0, 0);
        lcdTimer->display(displayTime.addSecs(elapsedSeconds).toString("hh:mm:ss"));
    };

    QObject::connect(timer, &QTimer::timeout, [&]() {
        if (timerRunning) {
            elapsedSeconds++;
            updateTimeDisplay();
        }
    });
    timer->start(1000);

    // Connexions des boutons
    QObject::connect(startButton, &QPushButton::clicked, [&]() {
        timerRunning = true;
        startTime = QTime::currentTime().addSecs(-elapsedSeconds); // Ajustement du startTime
    });

    QObject::connect(pauseButton, &QPushButton::clicked, [&]() {
        timerRunning = false;
    });

    // Ajout des widgets dans la barre de contrôle
    controlBar->addWidget(startButton);
    controlBar->addWidget(pauseButton);
    controlBar->addWidget(stopButton);
    controlBar->addWidget(rewindButton);
    controlBar->addWidget(forwardButton);
    controlBar->addStretch();
    controlBar->addWidget(lcdTimer);
    controlBar->addWidget(application_menu);

    controlBar->setSpacing(15);
    controlBar->setContentsMargins(15, 15, 15, 15);

    // Ajout du header au layout principal
    mainLayout->addLayout(controlBar);

    // Ajout des onglets au layout principal
    mainLayout->addWidget(tabWidget);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

}

void MainView::start() {
    show();
    std::cout << "View has started." << std::endl;
}

// void MainView::addToScene(QGraphicsEllipseItem *item) {
//     graphicsScene->addItem(item);
//     // connect(mobilePoint, &MobilePoint::positionUpdated, this, &MainView::onPositionUpdated);;
//     std::cout << "Mobile point added to scene " << std::endl;
// }


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
