#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "transport.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void addTypes(classes_t *head);
    QString getSelectedType() const;
    std::map<std::string, std::string> getFields() const;
    void addObj(std::string name, std::map<std::string, std::string> map);

    // QString getEnteredName() const;
    // double getEnteredAltitude() const;
    // double getEnteredSpeed() const;
    // int getEnteredWheels() const;


private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    classes_t *head;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
