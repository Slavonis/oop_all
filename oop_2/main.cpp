#include "mainwindow.h"
#include <QApplication>

#include "figure_list.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.myShapes = new figure_list ();
    return a.exec();
}
