#include "mainwindow.h"
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Créer le widget principal
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Créer un layout vertical
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Créer la liste des commandes
    orderList = new QListWidget(this);
    layout->addWidget(orderList);

    // Créer un bouton pour ajouter des commandes
    addOrderButton = new QPushButton("Ajouter une commande", this);
    layout->addWidget(addOrderButton);

    // Créer un label pour afficher les messages de debug
    debugLabel = new QLabel("Debug: En attente de l'ajout de commande", this);
    layout->addWidget(debugLabel);

    // Connecter le bouton à la fonction d'ajout de commande
    connect(addOrderButton, &QPushButton::clicked, this, &MainWindow::onAddOrderClicked);

    // Initialiser la fenêtre principale
    setWindowTitle("Gestion des commandes");
    resize(400, 300);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onAddOrderClicked()
{
    // Ajouter une nouvelle commande à la liste
    QString orderDetails = "Commande #" + QString::number(orderList->count() + 1);
    qDebug() << "Ajout de la commande: " << orderDetails;  // Message de debug

    orderList->addItem(orderDetails);

    // Mettre à jour le message de debug
    debugLabel->setText("Debug: Commande ajoutée: " + orderDetails);
}
