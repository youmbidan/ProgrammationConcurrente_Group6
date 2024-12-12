#ifndef CHEFVIEW_H
#define CHEFVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include "ChefController.h"

class ChefView : public QWidget {
    Q_OBJECT

private:
    ChefController* controller;
    QPushButton* addOrderButton;
    QListWidget* orderListWidget;

public:
    explicit ChefView(ChefController* controller, QWidget *parent = nullptr);

public slots:
    void onAddOrderClicked();
    void onOrderCompleted(int orderId); // Affiche la commande terminée
};

#endif // CHEFVIEW_H
