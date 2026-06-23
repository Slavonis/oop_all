#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include <QString>
#include <QDataStream>
class Vehicle {
protected:
    QString m_brand; int m_year; double m_price;
public:
    Vehicle(const QString& brand, int year, double price);
    virtual ~Vehicle() = default;
    virtual QString type() const = 0;
    virtual void serialize(QDataStream& s) const = 0;
    virtual void deserialize(QDataStream& s) = 0;
    QString brand() const; int year() const; double price() const;
    void setBrand(const QString& b); void setYear(int y); void setPrice(double p);
};
#endif
