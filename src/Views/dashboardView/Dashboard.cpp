#include "Dashboard.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QGraphicsDropShadowEffect>

#include <QScrollArea>
#include <QPainter>
#include <QFrame>

Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent) {
    setWindowTitle("Tableau de bord");
    resize(1200, 800); // Taille par défaut de la fenêtre

    // Création d'une zone défilable
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    // Widget principal contenant le contenu
    QWidget *contentWidget = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(contentWidget);
    mainLayout->setContentsMargins(20, 20, 20, 20); // Marges autour du contenu
    mainLayout->setSpacing(10); // Espacement entre les sections

    // En-tête
    QLabel *title = new QLabel("<h1 style='color: #0078D7;'>Tableau de bord du Restaurant</h1>");
    title->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(title);

    // Section 1 : Vue d'ensemble
    QGridLayout *overviewLayout = new QGridLayout();
    overviewLayout->setHorizontalSpacing(20);
    overviewLayout->setVerticalSpacing(20);

    QLabel *statusLabel = createMetricCard("Statut", "Ouvert", "#28A745");
    QLabel *clientsLabel = createMetricCard("Clients en salle", "25", "#0078D7");
    QLabel *tablesLabel = createMetricCard("Occupation des tables", "8/10", "#FFC107");
    QLabel *waitTimeLabel = createMetricCard("Temps d'attente moyen", "5 min", "#DC3545");

    overviewLayout->addWidget(statusLabel, 0, 0);
    overviewLayout->addWidget(clientsLabel, 0, 1);
    overviewLayout->addWidget(tablesLabel, 0, 2);
    overviewLayout->addWidget(waitTimeLabel, 0, 3);
    mainLayout->addLayout(overviewLayout);

    // Séparation visuelle
    mainLayout->addWidget(createSeparator());

    // Section 2 : Suivi des stocks
    QLabel *stocksTitle = new QLabel("<h2>Suivi des Stocks</h2>");
    stocksTitle->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(stocksTitle);

    QGridLayout *stocksLayout = new QGridLayout();
    stocksLayout->setHorizontalSpacing(20);

    stocksLayout->addWidget(createStockCard("Tomates", "80%", "#0078D7"), 0, 0);
    stocksLayout->addWidget(createStockCard("Carottes", "60%", "#FFC107"), 0, 1);
    stocksLayout->addWidget(createStockCard("Viande", "30%", "#DC3545"), 0, 2);
    stocksLayout->addWidget(createStockCard("Œufs", "50%", "#6C757D"), 0, 3);

    mainLayout->addLayout(stocksLayout);

    // Séparation visuelle
    mainLayout->addWidget(createSeparator());

    // Section 3 : Suivi du matériel
    QLabel *materialsTitle = new QLabel("<h2>Matériel Disponible</h2>");
    materialsTitle->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(materialsTitle);

    QGridLayout *materialsLayout = new QGridLayout();
    materialsLayout->setHorizontalSpacing(20);

    materialsLayout->addWidget(createStockCard("Assiettes", "90%", "#28A745"), 0, 0);
    materialsLayout->addWidget(createStockCard("Marmites", "70%", "#FFC107"), 0, 1);
    materialsLayout->addWidget(createStockCard("Verres", "20%", "#DC3545"), 0, 2);

    mainLayout->addLayout(materialsLayout);

    // Séparation visuelle
    mainLayout->addWidget(createSeparator());

    // Section 4 : Alertes critiques
    QLabel *alertsTitle = new QLabel("<h2>Alertes Critiques</h2>");
    alertsTitle->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(alertsTitle);

    QVBoxLayout *alertsLayout = new QVBoxLayout();
    alertsLayout->setSpacing(10);

    // Ajouter plusieurs alertes
    alertsLayout->addWidget(createAlertCard("Stock de viande faible !", "#DC3545"));
    alertsLayout->addWidget(createAlertCard("Verres presque épuisés !", "#DC3545"));
    alertsLayout->addWidget(createAlertCard("Assiettes insuffisantes pour le prochain service.", "#FFC107"));

    mainLayout->addLayout(alertsLayout);

    // Ajout du contenu au scrollArea
    contentWidget->setLayout(mainLayout);
    scrollArea->setWidget(contentWidget);

    // Layout principal de la fenêtre
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(scrollArea);
    setLayout(layout);
}

QLabel* Dashboard::createMetricCard(const QString &title, const QString &value, const QString &color) {
    QLabel *label = new QLabel(QString("<div style='text-align:center;'>"
                                       "<h3>%1</h3>"
                                       "<p style='font-size:24px; color:%2;'><b>%3</b></p>"
                                       "</div>").arg(title).arg(color).arg(value));
    label->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    label->setLineWidth(2);
    label->setFixedSize(300, 120);
    return label;
}

QLabel* Dashboard::createStockCard(const QString &item, const QString &status, const QString &color) {
    QLabel *label = new QLabel(QString("<div style='text-align:center;'>"
                                       "<h3>%1</h3>"
                                       "<p style='font-size:24px; color:%2;'><b>%3</b></p>"
                                       "</div>").arg(item).arg(color).arg(status));
    label->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    label->setLineWidth(2);
    label->setFixedSize(250, 100);
    return label;
}

QFrame* Dashboard::createSeparator() {
    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    line->setStyleSheet("color: #ccc; margin: 20px 0;");
    return line;
}

QLabel* Dashboard::createAlertCard(const QString &message, const QString &color) {
    // Créer le label avec le message de l'alerte
    QLabel *label = new QLabel(QString("<div style='text-align:left;'>"
                                       "<p style='font-size:18px; color:%1;'><b>⚠ %2</b></p>"
                                       "</div>").arg(color).arg(message));
    label->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    label->setLineWidth(2);
    label->setFixedSize(600, 60);

    // Appliquer l'effet de luisance
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();
    shadowEffect->setBlurRadius(15); // Rayon de flou
    shadowEffect->setXOffset(0);     // Pas de décalage horizontal
    shadowEffect->setYOffset(0);     // Pas de décalage vertical
    shadowEffect->setColor(QColor(color).lighter(150)); // Couleur de l'effet (plus clair)
    
    label->setGraphicsEffect(shadowEffect);  // Appliquer l'effet au label

    return label;
}
