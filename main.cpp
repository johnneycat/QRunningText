#include "mainwindow.h"
#include "textticker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    TextTicker w;
//    w.show();
    return a.exec();
}
