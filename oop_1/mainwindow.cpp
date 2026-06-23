#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include "./ui_mainwindow.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "ellips.h"
#include "triangle.h"
#include "parallel.h"

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



void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::white);
    //painter.setBrush(Qt::cyan);
    for(list_t* i = shapes->getList(); i != nullptr; i = i->next){
        if(i->shape_tp == this->shape){
            switch (i->shape_tp) {
            case CIRCLE: {
                Circle* circ = static_cast<Circle*>(i->shape);
                painter.drawEllipse(circ->getX1(), circ->getY1(), circ->getRadius() * 2, circ->getRadius() * 2);
                break;
            }
            case RECTANGLE: {
                Rectangle* rect = static_cast<Rectangle*>(i->shape);
                painter.drawRect(rect->getX1(), rect->getY1(), rect->getX2(), rect->getY2());
                break;
            }
            case LINE: {
                Line* line = static_cast<Line*>(i->shape);
                painter.drawLine(line->getX1(), line->getY1(), line->getX2(), line->getY2());
                break;
            }
            case ELLIPS: {
                Ellips* ellip = static_cast<Ellips*>(i->shape);
                painter.drawEllipse(ellip->getX1(), ellip->getY1(), ellip->getWidth(), ellip->getHeight());
                break;
            }
            case TRIANG: {
                Triangle* triang = static_cast<Triangle*>(i->shape);
                painter.drawPolygon({QPointF(triang->getX1(), triang->getY1()), QPointF(triang->getX2(), triang->getY2()), QPointF(triang->getX3(), triang->getY3())});
                break;
            }
            case PARALLEL: {
                Parallel* parallel = static_cast<Parallel*>(i->shape);
                painter.drawPolygon({QPointF(parallel->getX1(), parallel->getY1()), QPointF(parallel->getX2(), parallel->getY2()), QPointF(parallel->getX3(), parallel->getY3()), QPointF(parallel->getX4(), parallel->getY4())});
                break;
            }
            default:
                break;
            }
        }
    }

}



void MainWindow::on_pushButton_2_clicked()
{
    this->shape = CIRCLE;
    this->update();
}

void MainWindow::on_pushButton_6_clicked()
{
    this->shape = RECTANGLE;
    this->update();
}

void MainWindow::on_pushButton_4_clicked()
{
    this->shape = LINE;
    this->update();
}


void MainWindow::on_pushButton_5_clicked()
{
    this->shape = ELLIPS;
    this->update();
}


void MainWindow::on_pushButton_3_clicked()
{
    this->shape = TRIANG;
    this->update();
}


void MainWindow::on_pushButton_clicked()
{
    this->shape = PARALLEL;
    this->update();
}

