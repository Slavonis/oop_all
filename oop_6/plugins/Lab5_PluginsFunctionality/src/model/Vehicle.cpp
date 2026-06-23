#include "model/Vehicle.hpp"
Vehicle::Vehicle(const QString& brand, int year, double price)
    : m_brand(brand), m_year(year), m_price(price) {}
QString Vehicle::brand() const { return m_brand; }
int     Vehicle::year()  const { return m_year; }
double  Vehicle::price() const { return m_price; }
void Vehicle::setBrand(const QString& b) { m_brand = b; }
void Vehicle::setYear(int y)             { m_year  = y; }
void Vehicle::setPrice(double p)         { m_price = p; }
