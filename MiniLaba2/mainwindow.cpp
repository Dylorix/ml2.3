#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include "point.h"
#include <QPaintEvent>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Point *pointPE = new Point(event->x(),event->y());
    pointPE->setSize(pointPE->getSize()+i);
    if (i>4)
        pointPE->setW(2);
    if(i<10) {
        points[i]=pointPE;
        i++;
        repaint();
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter (this);
    if(i){
        for(int k = 0;k<i;k++) {
        Point *pointPE = points[k];
        pointPE->draw(&painter);
        }
    }
}
