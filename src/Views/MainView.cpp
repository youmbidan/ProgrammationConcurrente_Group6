// mainView.cpp
#include "mainView.h"

MainView::MainView(int argc, char *argv[]){
  this->argc = argc;
  this->argv = argv;
}

void MainView::start() {
    QCoreApplication app(argc, argv);
    QWidget mainWindow;

    mainWindow.setFixedSize(500, 500);
    mainWindow.setWindowTitle("Main Application");

    mainWindow.show();
    app.exec();
}
