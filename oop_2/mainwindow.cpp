#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QMessageBox>
#include "./ui_mainwindow.h"
#include "qmyframe.h"
#include "qt_painter_visitor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->frame, &QMyFrame::mouseDown, this, &MainWindow::on_frame_mouseDown);
    this->curClck = 0;
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

    qt_painter_visitor drawer(painter);
    for (list_t* i = myShapes->getList(); i != nullptr; i = i->next) {
        if (i->shape_tp == this->shape) {
            if (i->shape) {
                i->shape->accept(&drawer);
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

void MainWindow::on_frame_mouseDown(const QPoint pos)
{
    points[curClck] = pos;
    switch(this->shape){
    case CIRCLE:
        if (curClck == 3){
            int rx = abs(points[1].x() - points[2].x());
            int ry = abs(points[1].y() - points[2].y());
            int r = static_cast<int>(sqrt(rx*rx + ry*ry));
            myShapes->addShape(CIRCLE, {r, ui->gridLayoutWidget->geometry().x() + points[1].x() - r,ui->gridLayoutWidget->geometry().y() + points[1].y() - r});
            curClck = -1;
            this->update();
        }
        break;
    case RECTANGLE:
        if (curClck == 3){
            int shift_x = ui->gridLayoutWidget->geometry().x();
            int shift_y = ui->gridLayoutWidget->geometry().y();
            myShapes->addShape(RECTANGLE, {shift_x + points[1].x(),shift_y + points[1].y(), shift_x + points[2].x(),shift_y + points[2].y()});
            curClck = -1;
            this->update();
        }
        break;
    case LINE:
        if (curClck == 3){
            int shift_x = ui->gridLayoutWidget->geometry().x();
            int shift_y = ui->gridLayoutWidget->geometry().y();
            myShapes->addShape(LINE, {shift_x + points[1].x(),shift_y + points[1].y(), shift_x + points[2].x(),shift_y + points[2].y()});
            curClck = -1;
            this->update();
        }
        break;
    case ELLIPS:
        if (curClck == 5){
            int w = abs(points[1].x() - points[4].x()) * 2;
            int h = abs(points[1].y() - points[2].y()) * 2;
            int shift_x = ui->gridLayoutWidget->geometry().x();
            int shift_y = ui->gridLayoutWidget->geometry().y();
            myShapes->addShape(ELLIPS, {shift_x + points[2].x() - w/2,shift_y + points[2].y() , w, h});
            curClck = -1;
            this->update();
        }
        break;
    case TRIANG:
        if (curClck == 5){
            int shift_x = ui->gridLayoutWidget->geometry().x();
            int shift_y = ui->gridLayoutWidget->geometry().y();
            myShapes->addShape(TRIANG, {shift_x + points[1].x(),shift_y + points[1].y(), shift_x + points[2].x(),shift_y + points[2].y(), shift_x + points[4].x(),shift_y + points[4].y()});

            curClck = -1;
            this->update();
        }
        break;
    case PARALLEL:
        if (curClck == 5){
            int shift_x = ui->gridLayoutWidget->geometry().x();
            int shift_y = ui->gridLayoutWidget->geometry().y();
            myShapes->addShape(PARALLEL, {shift_x + points[1].x(),shift_y + points[1].y(), shift_x + points[2].x(),shift_y + points[2].y(), shift_x + points[4].x(),shift_y + points[4].y()});
            curClck = -1;
            this->update();
        }
        break;
    case NONE:
        break;
    }
    curClck++;


    /*QString strMsg = "";
    QMessageBox::information(this, "Warning", strMsg
                                                  + "\n x()=" + QString::number(ui->gridLayoutWidget->geometry().x() + pos.x())
                                                  + "\n y()=" + QString::number(ui->gridLayoutWidget->geometry().y() + pos.y()));*/

}

