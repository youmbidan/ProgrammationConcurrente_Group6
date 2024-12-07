#include "mainView.h"
#include <QVBoxLayout>
#include <QTabWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QStyle>
#include <QApplication>
#include <iostream>

MainView::MainView(QWidget* parent)
    : QMainWindow(parent), elapsedSeconds(0), timerRunning(false)
{
    // Configuration de la fenêtre principale
    setWindowTitle("Gestion du Restaurant");
    resize(1024, 768);

    kitchenView = new  KitchenView();
    dinningRoomView = new  DinningRoomView();
    // Création des onglets
    QTabWidget *tabWidget = new QTabWidget(this);
    tabWidget->addTab(dinningRoomView, "Restaurant"); // Remplacez par vos vues réelles
    tabWidget->addTab(kitchenView, "Cuisine");

    // Création de la barre de contrôle
    QHBoxLayout* controlBar = new QHBoxLayout();

    // Boutons
    QPushButton* startButton = createButton(QStyle::SP_MediaPlay, "Start");
    QPushButton* pauseButton = createButton(QStyle::SP_MediaPause, "Pause");
    QPushButton* stopButton = createButton(QStyle::SP_MediaStop, "Stop");
    QLCDNumber* lcdTimer = new QLCDNumber(this);
    lcdTimer->setDigitCount(8);

    // Ajout des widgets à la barre de contrôle
    controlBar->addWidget(startButton);
    controlBar->addWidget(pauseButton);
    controlBar->addWidget(stopButton);
    controlBar->addStretch();
    controlBar->addWidget(lcdTimer);

    // Timer pour mettre à jour l'affichage
    timer = new QTimer(this); // Timer persistant
    connect(timer, &QTimer::timeout, this, &MainView::updateTimerDisplay);

    // Connexions des boutons
    connect(startButton, &QPushButton::clicked, this, &MainView::startTimer);
    connect(pauseButton, &QPushButton::clicked, this, &MainView::pauseTimer);
    connect(stopButton, &QPushButton::clicked, this, &MainView::resetTimer);

    // Layout principal
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addLayout(controlBar);
    mainLayout->addWidget(tabWidget);

    // Création du widget central
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

}

// Création d'un bouton stylisé
QPushButton* MainView::createButton(QStyle::StandardPixmap iconType, const QString& tooltip) {
    QPushButton* btn = new QPushButton();
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
}

// Lancer le programme
void MainView::start() {
    show();
    std::cout << "View has started." << std::endl;
}

// Gestion des actions
void MainView::startTimer() {
    if (!timerRunning) {
        timerRunning = true;
        timer->start(1000); // Mise à jour chaque seconde
    }
}

void MainView::pauseTimer() {
    timerRunning = false;
    timer->stop();
}

void MainView::resetTimer() {
    timer->stop();
    timerRunning = false;
    elapsedSeconds = 0;
    updateTimerDisplay();
}

void MainView::updateTimerDisplay() {
    if (timerRunning) {
        elapsedSeconds++;
    }
    QTime displayTime(0, 0, 0);
    QString timeString = displayTime.addSecs(elapsedSeconds).toString("hh:mm:ss");
    findChild<QLCDNumber*>()->display(timeString); // Mise à jour du LCD
}


KitchenView* MainView::getKitchenView() {
    return kitchenView;
}

DinningRoomView* MainView::getDinningRoomView() {
    return dinningRoomView;
}

