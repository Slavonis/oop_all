#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <QtWidgets>
#include <string>

#include <nlohmann/json.hpp>

typedef enum type{
    STRING,
    INT,
    DOUBLE
} type_t;

class transport {
protected:
    std::string name = "New transport";
    double speed = 0.0;
public:
    transport();
    ~transport() = default;

    virtual std::string getTypeName() = 0;

    virtual nlohmann::json toJson();
    virtual void fromJson(const nlohmann::json& j);
    virtual std::string getDisplayString();

    virtual transport* create(const std::map<std::string, std::string>& fields);
    virtual std::map<std::string, type_t> getFields();
    virtual std::map<std::string, std::string> getToChange();
};

typedef struct classes
{
    transport* transport;
    classes* next;
}classes_t;

#endif // TRANSPORT_H
