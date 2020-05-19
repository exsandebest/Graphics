#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(600, 600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setPen(QPen(Qt::black,1,Qt::SolidLine, Qt::FlatCap));
    painter.translate(300, 300);
    painter.scale(1,-1);

    for(int i = -300; i<=300; ++i){
        painter.drawPoint(i,0);
    }
    for (int i = -300; i<=300; ++i){
        painter.drawPoint(0,i);
    }
    painter.setPen(QPen(Qt::black,5,Qt::SolidLine, Qt::FlatCap));
    for (int x = -300; x <=300; ++x){
        for (int y = -300; y <=300; ++y){
            if (abs(3*abs(x-30) + 2*abs(y-60) - 180)<2){
                painter.drawPoint(x,y);
            } else if (abs(5*y - (2*x - 570)) <2 ){
                painter.drawPoint(x,y);
            } else if (abs((x-60)*(x-60) + (y+180)*(y+180) - 3600)<64){
                painter.drawPoint(x,y);
            } else if ((y ==120 && x<=90 && x>=-30) || (y == -60 && x<=90 && x>=-30)
                       || (x == 90 && y>=-60 && y <= 120) || (x ==-30 && y>=-60 && y <= 120)){
                painter.drawPoint(x,y);
            } else if ((y == -120 && x>=0 && x<= 300) || (y == -300 && x>=0 && x<= 300)
                       || (x == 0 && y>=-300 && y<=-120) || (x == 300 && y>=-300 && y<=-120)){
                painter.drawPoint(x,y);
            } else if (abs(-1*(x*x) -300*(x) -17100 -30*y) < 58){
                painter.drawPoint(x,y);
            } else if ( abs(x*x -420*x + 36000 - 45*y) < 58){
                painter.drawPoint(x,y);
            }

        }
    }

    painter.setPen(QPen(Qt::green,1,Qt::SolidLine, Qt::FlatCap));

    for (int x = -300; x<=300; ++x){
        for(int y = -300; y<=300; ++y){

            bool rhombusIn = (3*abs(x-30) + 2*abs(y-60) <= 180);
            bool cricleIn = ((x-60)*(x-60) + (y+180)*(y+180) <= 3600);
            bool rectangleFirstIn = (y<=120 && y>=-60 && x>=-30 && x<=90);
            bool rhRLineOut = (2*y > -3*x +390);
            bool rhLLineOut = (2*y > 3*x+210);
            bool parableFirstIn = (-1*(x*x) -300*(x) -17100 >= 30*y);
            bool lineUp = 5*y > (2*x - 570);
            bool parableSecondIn = (x*x -420*x + 36000 <= 45*y);
            bool rectangleSecondIn = (y>=-300 && y<= -120 && x>=0 && x<=300);
            bool triangle = (x>=0 && x<= 60 && y <=-120 && y >=-180 && ((x-60)*(x-60) + (y+180)*(y+180) >= 3600));
            if ((rhombusIn && !rectangleFirstIn) || (rectangleFirstIn && !rhombusIn && !rhRLineOut) || (parableFirstIn && lineUp) || (parableSecondIn && lineUp)
                    || (rectangleSecondIn && !parableSecondIn && !cricleIn && !triangle)){
                painter.drawPoint(x,y);
            }
        }
    }
}
