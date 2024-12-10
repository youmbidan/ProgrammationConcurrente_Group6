#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddOrderClicked();  // Slot pour gérer l'ajout de commande

private:
    QListWidget *orderList;    // Liste des commandes
    QPushButton *addOrderButton; // Bouton pour ajouter des commandes
    QLabel *debugLabel;         // Label pour afficher les messages de debug
};

#endif // MAINWINDOW_H
