#include "MainView.h"
#include "dashboardView/Dashboard.h"
#include <QGraphicsEllipseItem>
#include <QMessageBox>
#include <random>
#include <iostream>
#include <QLabel>
#include <QVBoxLayout>

#include <QPushButton>
#include <QGridLayout>
#include <QScrollArea>
#include <QScrollBar>
#include "SetupView/SetupView.h"
#include <QApplication>
#include <QPixmap>
#include <QPropertyAnimation>

class MenuView : public QWidget {
public:
    MenuView(QWidget* parent = nullptr) : QWidget(parent) {
        setWindowTitle("Menu du Jour");
        setFixedSize(1024, 768); // Augmenter la taille de la fenêtre pour plus de contenu

    
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->setSpacing(20);
        layout->setContentsMargins(20, 20, 20, 20);

        // Titre
        QLabel* title = new QLabel("🍽️ Menu du Jour 🍽️");
        title->setStyleSheet(R"(
            QLabel {
                font-size: 26px;
                font-weight: bold;
                color: #d32f2f;
                text-align: center;
                text-shadow: 1px 1px 3px #aaaaaa;
            }
        )");
        title->setAlignment(Qt::AlignCenter);
        layout->addWidget(title);

        // Scroll area pour gérer le contenu
        QScrollArea* scrollArea = new QScrollArea();
        scrollArea->setWidgetResizable(true);

        QWidget* scrollContent = new QWidget();
        QGridLayout* gridLayout = new QGridLayout(scrollContent);
        gridLayout->setSpacing(15);

        QStringList dishes = {
            "Pizza Margherita|12000fcfa|:/assets/pizza.png",
            "Burger au poulet|10000fcfa|:/assets/burger.png",
            "Pâtes Carbonara|12200fcfa|:/assets/lasagne.png",
            "Sushi varié|15000fcfa|:/assets/sushi.png",
            "Poulet roti|8500fcfa|:/assets/poulet.png"
        };

        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(dishes.begin(), dishes.end(), gen);

        for (int i = 0; i < dishes.size(); ++i) {
            QStringList dishDetails = dishes[i].split('|');
            QString name = dishDetails[0];
            QString price = dishDetails[1];
            QString imagePath = dishDetails[2];

            QFrame* dishCard = new QFrame();
            dishCard->setFixedSize(220, 280); // Dimensions ajustées
            dishCard->setStyleSheet(R"(
                QFrame {
                    background-color: #ffffff;
                    border: 1px solid #e0e0e0;
                    border-radius: 10px;
                    padding: 10px;
                    box-shadow: 2px 2px 8px rgba(0, 0, 0, 0.1);
                }
            )");

            QVBoxLayout* cardLayout = new QVBoxLayout(dishCard);
            cardLayout->setAlignment(Qt::AlignCenter);

            QLabel* imageLabel = new QLabel();
            imageLabel->setPixmap(QPixmap(imagePath).scaled(120, 120, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            imageLabel->setAlignment(Qt::AlignCenter);

            QLabel* nameLabel = new QLabel(name);
            nameLabel->setStyleSheet("font-size: 14px; font-weight: bold; color: #333;");
            nameLabel->setAlignment(Qt::AlignCenter);

            QLabel* priceLabel = new QLabel(price);
            priceLabel->setStyleSheet("font-size: 12px; color: #00796b;");
            priceLabel->setAlignment(Qt::AlignCenter);

            cardLayout->addWidget(imageLabel);
            cardLayout->addWidget(nameLabel);
            cardLayout->addWidget(priceLabel);

            gridLayout->addWidget(dishCard, i / 2, i % 2); // Grille 2x3
        }

        scrollContent->setLayout(gridLayout);
        scrollArea->setWidget(scrollContent);
        layout->addWidget(scrollArea);

        // Bouton de rafraîchissement
        QPushButton* refreshButton = new QPushButton("🔄 Rafraîchir");
        refreshButton->setStyleSheet(R"(
            QPushButton {
                font-size: 14px;
                background-color: #ff9800;
                color: white;
                border: none;
                border-radius: 10px;
                padding: 10px 20px;
            }
        )");
        connect(refreshButton, &QPushButton::clicked, [this]() {
            this->close();
            MenuView* newMenu = new MenuView();
            newMenu->setAttribute(Qt::WA_DeleteOnClose);
            newMenu->show();
        });
        layout->addWidget(refreshButton, 0, Qt::AlignCenter);

        // Bouton de fermeture
        QPushButton* closeButton = new QPushButton("Fermer");
        closeButton->setStyleSheet(R"(
            QPushButton {
                font-size: 14px;
                background-color: #4caf50;
                color: white;
                border: none;
                border-radius: 10px;
                padding: 10px 20px;
            }
        )");
        connect(closeButton, &QPushButton::clicked, this, &QWidget::close);
        layout->addWidget(closeButton, 0, Qt::AlignCenter);
    }
};
MainView::MainView(QWidget* parent)
    : QMainWindow(parent) {
    setWindowTitle("Gestion du Restaurant");
    resize(1024, 768);

    kitchenView = new  KitchenView();
    dinningRoomView = new  DinningRoomView();
    // Création des onglets
    QTabWidget *tabWidget = new QTabWidget(this);
    tabWidget->addTab(dinningRoomView, "Restaurant"); // Remplacez par vos vues réelles
    tabWidget->addTab(kitchenView, "Cuisine");

    QFrame* mainFrame = new QFrame;
    mainFrame->setStyleSheet("background-color: #e0e0e0; border-radius: 10px; padding: 20px;");
    QVBoxLayout* mainLayout = new QVBoxLayout(mainFrame);

    QHBoxLayout* controlBar = new QHBoxLayout();

    auto createButton = [](const QStyle::StandardPixmap iconType, const QString& tooltip) -> QPushButton* {
        QPushButton* btn = new QPushButton();
        btn->setIcon(QApplication::style()->standardIcon(iconType));
        btn->setIconSize(QSize(24, 24));
        btn->setFixedSize(48, 48);
        btn->setToolTip(tooltip);
        btn->setStyleSheet(R"(
            QPushButton {
                background-color: #22e7c2;
                border: none;
                color: white;
                border-radius: 24px;
                font-size: 16px;
            }
            QPushButton:hover {
                background-color: #18d7be;
            }
            QPushButton:pressed {
                background-color: #3e8e41;
            }
        )");
        return btn;
    };

    QPushButton* startButton = createButton(QStyle::SP_MediaPlay, "Start");
    QPushButton* pauseButton = createButton(QStyle::SP_MediaPause, "Pause");
    QPushButton* stopButton = createButton(QStyle::SP_MediaStop, "Stop");
    QPushButton* dashboardButton = createButton(QStyle::SP_FileDialogInfoView, "Dashboard");
    QPushButton* menuButton = new QPushButton();
    menuButton->setIcon(QIcon(":/assets/menu.png")); // Assurez-vous que l'icône est disponible dans votre projet
    menuButton->setIconSize(QSize(32, 32));
    menuButton->setFixedSize(48, 48);
    menuButton->setToolTip("Menu du Jour");
    menuButton->setStyleSheet(R"(
        QPushButton {
            background-color: #ffa726;
            border: none;
            color: white;
            border-radius: 24px;
            font-size: 16px;
        }
        QPushButton:hover {
            background-color: #ff9800;
        }
        QPushButton:pressed {
            background-color: #e65100;
        }
    )");

    QObject::connect(dashboardButton, &QPushButton::clicked, [&]() {
        Dashboard* dashboard = new Dashboard();
        dashboard->show();
    });

    QObject::connect(menuButton, &QPushButton::clicked, [&]() {
        MenuView* menuView = new MenuView();
        menuView->setAttribute(Qt::WA_DeleteOnClose); // Libérer la mémoire à la fermeture
        menuView->show();
    });

    controlBar->addWidget(startButton);
    controlBar->addWidget(pauseButton);
    controlBar->addWidget(stopButton);
    controlBar->addWidget(dashboardButton);
    controlBar->addWidget(menuButton);
    controlBar->addStretch();

    controlBar->setSpacing(15);
    controlBar->setContentsMargins(15, 15, 15, 15);

    mainLayout->addLayout(controlBar);
    mainLayout->addWidget(tabWidget);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

void MainView::start() {
    show();
    std::cout << "View has started." << std::endl;
}

KitchenView* MainView::getKitchenView() {
    return kitchenView;
}

DinningRoomView* MainView::getDinningRoomView() {
    return dinningRoomView;
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
