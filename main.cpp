#include  <QtWidgets/QApplication>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QFrame>

QFrame* createColoredSquare(const QString& color, int size = 100) {
    QFrame* square = new QFrame();
    square->setStyleSheet(QString("background-color: %1; border: 1px solid black;").arg(color));
    square->setFixedSize(size, size);
    return square;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Création d'une fenêtre principale
    QWidget window;
    window.setWindowTitle("Interface avec Qt");
    window.showMinimized(); // Met la fenêtre en plein écran

    // Création d'une disposition en grille
    QGridLayout* gridLayout = new QGridLayout();

    // Ajouter des carrés colorés à la grille
    QStringList colors = {"red", "green", "blue", "yellow", "purple", "orange", "cyan", "pink"};
    int numRows = 4, numCols = 4; // Taille de la grille

    int colorIndex = 0;
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            QFrame* square = createColoredSquare(colors[colorIndex % colors.size()]);
            gridLayout->addWidget(square, row, col);
            colorIndex++;
        }
    }

    // Appliquer la disposition à la fenêtre
    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(gridLayout);
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(centralWidget);

    window.setLayout(mainLayout);

    // Afficher la fenêtre
    window.show();

    // Boucle de l'application
    return app.exec();
}
