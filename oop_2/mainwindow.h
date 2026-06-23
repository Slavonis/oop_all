#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "figure_list.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    shape_t shape = NONE;
    figure_list* myShapes;
    QPoint points[6] {};
    int curClck = 0;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_frame_mouseDown(const QPoint pos);

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    int pointers;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
