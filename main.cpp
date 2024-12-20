#include "src/Controllers/classDeclaration/MainController.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MobilePointView mobilePointView(250,250);
    MainView mainView(nullptr);
    MainController mainController(mainView);

    mainController.startMainView();

    return QApplication::exec();
}
