#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QLabel>
#include <QPainter>



int main(int argc, char *argv[])
{


    QApplication a(argc, argv);


    MainWindow win;
    win.resize(600,600);
    win.show();


    return a.exec();
}



