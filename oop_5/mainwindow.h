#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "transport.h"
#include "proc_interface.h"




QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    classes_t* addClass(transport* object, classes_t* head_te);

    void updateListUI();

private slots:
    void loadPlugins();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void loadProcessingPlugins();

    void buildSettingsMenu();

private:
    QList<proc_interface*> m_processingPlugins;
    proc_interface* m_activeProcessor = nullptr;

    classes_t* head_reg = nullptr;
    classes_t* head = nullptr;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
