#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <cstring>

class Car {
private:
    std::string m_make;
    std::string m_model;
    size_t m_year;
    double m_mileage;

public:
// constructors and deconstor
    Car();
    Car(const std::string& make, const std::string& model);
    Car(const std::string& make, const std::string& model, size_t year, double mileage);
    Car(const Car& rhs);
    Car(Car&& rhs);
    ~Car();

// Assignment operator
    Car& operator=(const Car& rhs);
    Car& operator=(Car&& rhs);

// setter functions
    void set_make(const std::string& make);
    void set_model(const std::string& model);
    void set_year(size_t year);
    void set_mileage(double mileage);
    void clear();

//member methods
    void displayInfo();
    void drive(double distance);
    void service();

};

#endif