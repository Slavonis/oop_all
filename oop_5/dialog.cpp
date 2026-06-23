#include "dialog.h"
#include "ui_dialog.h"
#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void  Dialog::addObj(std::string name, std::map<std::string, std::string> map){
    ui->comboBox->setCurrentText(QString::fromStdString(name));
    for (int i = ui->formLayout->rowCount() - 1; i > 0; i--){
        QLayoutItem* labelItem = ui->formLayout->itemAt(i, QFormLayout::LabelRole);
        QLayoutItem* fieldItem = ui->formLayout->itemAt(i, QFormLayout::FieldRole);

        if (labelItem && fieldItem) {
            QLabel* label = qobject_cast<QLabel*>(labelItem->widget());
            QDoubleSpinBox* d_spin_box = qobject_cast<QDoubleSpinBox*>(fieldItem->widget());
            QSpinBox* spin_box = qobject_cast<QSpinBox*>(fieldItem->widget());
            QLineEdit* edit = qobject_cast<QLineEdit*>(fieldItem->widget());
            if (label && d_spin_box) {
                std::string key = label->text().toStdString();
                std::string valueStr = map[key];
                d_spin_box->setValue(QString::fromStdString(valueStr).toDouble());
            } else if (label && edit) {
                std::string key = label->text().toStdString();
                std::string valueStr = map[key];
                edit->setText(QString::fromStdString(valueStr));
            } else if (label && spin_box) {
                std::string key = label->text().toStdString();
                std::string valueStr = map[key];
                spin_box->setValue(QString::fromStdString(valueStr).toLong());
            }
        }
    }
}

void  Dialog::addTypes(classes_t *hea){
    QStringList list;
    Dialog::head = hea;
    for (classes_t *itr = head; itr != nullptr; itr = itr->next){
        std::string str = itr->transport->getTypeName();
        if (!list.contains(str)){
            list.push_back(QString::fromStdString(str));
        }
    }
    ui->comboBox->addItems(list);
}

void Dialog::on_comboBox_currentTextChanged(const QString &arg1)
{
    for (int i = ui->formLayout->rowCount() - 1; i > 0; i--){
        ui->formLayout->removeRow(i);
    }
    for (classes_t *itr = head; itr != nullptr; itr = itr->next){
        std::string str = itr->transport->getTypeName();
        if (str == arg1.toStdString()){
            std::map<std::string, type_t> field = itr->transport->getFields();
            for (const auto& pair : field) {
                QString name = QString::fromStdString(pair.first);
                switch (pair.second){
                    case STRING: {
                        QLineEdit* strEdit = new QLineEdit(this);
                        ui->formLayout->addRow(name, strEdit);
                        break;
                    }
                    case INT:{
                        QSpinBox* spinBox = new QSpinBox(this);
                        spinBox->setMaximum(2000);
                        spinBox->setValue(0);
                        ui->formLayout->addRow(name, spinBox);
                        break;
                    }
                    case DOUBLE:{
                        QDoubleSpinBox* spinBox = new QDoubleSpinBox(this);
                        spinBox->setMaximum(2000);
                        spinBox->setValue(0.0);
                        ui->formLayout->addRow(name, spinBox);
                        break;
                    }
                }
            }
        }
    }
}

QString Dialog::getSelectedType() const {
    return ui->comboBox->currentText();
}

std::map<std::string, std::string> Dialog::getFields() const {
    std::map<std::string, std::string> map;
    for (int i = ui->formLayout->rowCount() - 1; i > 0; i--){
        QLayoutItem* labelItem = ui->formLayout->itemAt(i, QFormLayout::LabelRole);
        QLayoutItem* fieldItem = ui->formLayout->itemAt(i, QFormLayout::FieldRole);

        if (labelItem && fieldItem) {
            QLabel* label = qobject_cast<QLabel*>(labelItem->widget());
            QDoubleSpinBox* d_spin_box = qobject_cast<QDoubleSpinBox*>(fieldItem->widget());
            QSpinBox* spin_box = qobject_cast<QSpinBox*>(fieldItem->widget());
            QLineEdit* edit = qobject_cast<QLineEdit*>(fieldItem->widget());
            if (label && d_spin_box) {
                std::string key = label->text().toStdString();
                std::string valueStr = std::to_string(d_spin_box->value());
                map[key] = valueStr;
            } else if (label && edit) {
                std::string key = label->text().toStdString();
                std::string valueStr = edit->text().toStdString();
                map[key] = valueStr;
            } else if (label && spin_box) {
                std::string key = label->text().toStdString();
                std::string valueStr = std::to_string(spin_box->value());
                map[key] = valueStr;
            }
        }
    }
    return map;
}

