#pragma once

#include <string>
#include <stddef.h>

class IVehicle {
public:
    virtual start_engine() = 0;
    virtual stop_engine() = 0;
    virtual refuel() = 0;
    virtual ~IVehicle(){}

protected:
    std::string m_make;
    std::string m_model;
    size_t m_year;
    double m_mileage;
};

class Car : public IVehicle {
    
}