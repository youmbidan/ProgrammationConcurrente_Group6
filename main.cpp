#include <QtWidgets/QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QFrame>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QStyle>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>

class GlowingLabel : public QLabel
{
public:
    GlowingLabel(QWidget *parent = nullptr) : QLabel(parent)
    {
        setStyleSheet(R"(
            QLabel {
                border: 2px solid #a0522d;
                background-image: url(':/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/Assets/plancher3.jpg');
                border-radius: 10px;
                color: #2c3e50;
                font-size: 16px;
                padding: 10px;
            }
        )");
        effect = new QGraphicsDropShadowEffect(this);
        effect->setBlurRadius(20);
        effect->setColor(Qt::white);
        effect->setOffset(0, 0);
        setGraphicsEffect(effect);

        // Création de l'animation
        animation = new QPropertyAnimation(effect, "color");
        animation->setDuration(2000); // Durée de l'animation en millisecondes
        animation->setLoopCount(-1);  // Boucle infinie

        // Définir les couleurs de départ et de fin
        animation->setStartValue(QColor(255, 255, 255));
        animation->setEndValue(QColor(200, 200, 200));

        animation->start();
    }

private:
    QGraphicsDropShadowEffect *effect;
    QPropertyAnimation *animation;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Fenêtre principale
    QWidget window;
    window.setWindowTitle("Salle de Restaurant");
    window.resize(1024, 768);

    // Création du cadre principal
    QFrame *mainFrame = new QFrame(&window);
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

    // Nouveau bouton pour la cuisine (icône personnalisée, ajustez selon vos ressources)
    QPushButton *kitchenButton = new QPushButton();
    kitchenButton->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogApplyButton)); // Icône représentant la cuisine
    kitchenButton->setIconSize(QSize(24, 24));
    kitchenButton->setFixedSize(48, 48);
    kitchenButton->setToolTip("Kitchen");
    kitchenButton->setStyleSheet(R"(
        QPushButton {
            background-color: #FF9800;
            border: none;
            color: white;
            border-radius: 24px;
            font-size: 16px;
        }
        QPushButton:hover {
            background-color: #fb8c00;
        }
        QPushButton:pressed {
            background-color: #ef6c00;
        }
    )");

    // LCD pour le temps écoulé
    QLCDNumber *lcdTimer = new QLCDNumber();
    lcdTimer->setDigitCount(8);
    lcdTimer->setFixedHeight(50);
    lcdTimer->setStyleSheet("border: none; color: #2c3e50; background: transparent; font-size: 18px;");

    QTime startTime = QTime::currentTime();
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]()
                     {
        int elapsed = startTime.secsTo(QTime::currentTime());
        QTime displayTime(0, 0, 0);
        lcdTimer->display(displayTime.addSecs(elapsed).toString("hh:mm:ss")); });
    timer->start(1000);

    // Ajout des widgets dans la barre de contrôle
    controlBar->addWidget(startButton);
    controlBar->addWidget(pauseButton);
    controlBar->addWidget(stopButton);
    controlBar->addWidget(rewindButton);
    controlBar->addWidget(forwardButton);
    controlBar->addWidget(kitchenButton); // Ajout du bouton cuisine
    controlBar->addStretch();
    controlBar->addWidget(lcdTimer);
    controlBar->addWidget(application_menu);

    controlBar->setSpacing(15);
    controlBar->setContentsMargins(15, 15, 15, 15);

    // Ajout du header au layout principal
    mainLayout->addLayout(controlBar);

    // Création de la scène et de la vue pour la zone centrale
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);
    view->setSceneRect(0, 0, 1024, 768); // Ajustement de la scène pour qu'elle corresponde à la vue
    view->setStyleSheet(R"(
        QGraphicsView {
            border: none;
            background-image: url(':/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/Assets/plancher.jpeg');
            border-radius: 10px;
            box-shadow: 0px 0px 20px 10px rgba(0, 0, 0, 0.5);
        }
    )");

    // Ajout de décorations (images) dans la scène
    QPixmap pixmap(":/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/Assets/pancarte-removebg-preview.png");
    QGraphicsPixmapItem *decor1 = scene->addPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio));
    decor1->setPos(100, 100); // Positionnement initial

    // Fonction pour repositionner l'élément décoratif
    auto repositionDecoration = [scene, decor1](int x, int y)
    {
        decor1->setPos(x, y);
        scene->update();
    };

    // Exemple d'utilisation : repositionner l'élément décoratif à (200, 200)
    repositionDecoration(450, 5);

    mainLayout->addWidget(view);

    window.setLayout(mainLayout);
    window.show();

    return app.exec();
}
