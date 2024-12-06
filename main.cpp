#include "src/Controllers/classDeclaration/MainController.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainView mainView(nullptr);
    MainController mainController(mainView);

    mainController.startMainView();

    return QApplication::exec();
}
