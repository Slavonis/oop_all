#include "mainwindow.h"
#include <QApplication>

#include "figure_list.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.shapes = new figure_list ();
    w.shapes->addCircle(100, 500, 150);
    w.shapes->addRectangle(300, 100, 400, 150);
    //w.shapes->addCircle(50, 100, 100);
    //w.shapes->addCircle(11, 300, 70);
    w.shapes->addLine(300, 100, 500, 150);
    w.shapes->addEllips(300, 100, 350, 200);
    w.shapes->addTriangle(300, 150, 450, 400, 700, 150);
    w.shapes->addParallel(300, 150, 450, 400, 700, 450);
    return a.exec();
}
