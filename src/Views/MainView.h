// mainView.h
#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QCoreApplication>
#include <QWidget>

class MainView {
private:
    int argc;
    char **argv;

public:
    MainView(int argc, char *argv[]);
    void start();
};

#endif // MAINVIEW_H
