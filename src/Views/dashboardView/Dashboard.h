#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QLabel>
#include <QFrame>

class Dashboard : public QWidget {
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);

private:
    QLabel* createMetricCard(const QString &title, const QString &value, const QString &color);
    QLabel* createStockCard(const QString &item, const QString &status, const QString &color); // Déclaration ajoutée
    QLabel* createAlertCard(const QString &message, const QString &color); // Déclaration ajoutée
    QFrame* createSeparator();
};

#endif // DASHBOARD_H
