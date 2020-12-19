#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    w.setWindowTitle("Space Simulator - Andres Giraldo & Alejandro Gualteros");
    w.show();
    return a.exec();
}
