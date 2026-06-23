#ifndef EDIT_VEHICLE_DIALOG_HPP
#define EDIT_VEHICLE_DIALOG_HPP
#include "model/Vehicle.hpp"
#include <QDialog>
class QLineEdit; class QSpinBox; class QDoubleSpinBox;
class EditVehicleDialog final : public QDialog {
    Vehicle* m_vehicle;
    QLineEdit* m_brandEdit; QSpinBox* m_yearSpin; QDoubleSpinBox* m_priceSpin;
    void applyChanges();
public:
    explicit EditVehicleDialog(Vehicle* vehicle, QWidget* parent = nullptr);
};
#endif
