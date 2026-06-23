#include "ui/EditVehicleDialog.hpp"
#include <QDialogButtonBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>

EditVehicleDialog::EditVehicleDialog(Vehicle* vehicle, QWidget* parent)
    : QDialog(parent), m_vehicle(vehicle) {
    setWindowTitle("Edit Vehicle"); resize(400, 200);
    auto* layout = new QVBoxLayout(this);
    auto* form   = new QFormLayout();
    m_brandEdit = new QLineEdit(vehicle->brand());
    m_yearSpin  = new QSpinBox(); m_yearSpin->setRange(1900,2100); m_yearSpin->setValue(vehicle->year());
    m_priceSpin = new QDoubleSpinBox(); m_priceSpin->setRange(0,1e8); m_priceSpin->setValue(vehicle->price());
    form->addRow("Brand", m_brandEdit); form->addRow("Year", m_yearSpin); form->addRow("Price", m_priceSpin);
    layout->addLayout(form);
    auto* btns = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    layout->addWidget(btns);
    connect(btns, &QDialogButtonBox::accepted, this, [this]{ applyChanges(); accept(); });
    connect(btns, &QDialogButtonBox::rejected, this, &QDialog::reject);
}
void EditVehicleDialog::applyChanges() {
    m_vehicle->setBrand(m_brandEdit->text());
    m_vehicle->setYear(m_yearSpin->value());
    m_vehicle->setPrice(m_priceSpin->value());
}
