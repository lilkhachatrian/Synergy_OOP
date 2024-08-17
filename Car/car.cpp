#include "car.h"

// Implementing constructors

// default ctor
Car::Car() : m_make(""), m_model(""), m_year(0), m_mileage(0) {}
//constructor with parameters
Car::Car(const std::string& make, const std::string& model) : Car(make, model, 0, 0) {}
Car::Car(const std::string& make, const std::string& model, size_t year, double mileage) : 
     m_make(make), m_model(model), m_year(year), m_mileage(mileage) {}

//copy constructor
Car::Car(const Car& rhs) {
    m_make = rhs.m_make;
    m_model = rhs.m_model;
    m_year = rhs.m_year;
    m_mileage = rhs.m_mileage;
}

//move constructor
Car::Car(const Car&& rhs) {
    m_make = rhs.m_make;
    m_model = rhs.m_model;
    m_year = rhs.m_year;
    m_mileage = rhs.m_mileage;
}

//destructor
Car::~Car(){
}

//copy assignment operator
Car& Car::operator=(const Car& rhs) {
    if(this == &rhs) return *this;
    m_make = rhs.m_make;
    m_model = rhs.m_make;
    m_year = rhs.m_year;
    m_mileage = rhs.m_mileage;

    return *this;
}

// setter functions
void Car::set_make(const std::string& make){
    this->m_make = make;
}
void Car::set_model(const std::string& model){
    this->m_model = model;
}
void Car::set_year(size_t year){
    this->m_year = year;
}
void Car::set_mileage(double mileage){
    this->m_mileage = mileage;
}

//member methods
void Car::displayInfo(){
    std::cout << "Car manufacturer: " << m_make << std::endl;
    std::cout << "Car model: " << m_model << std::endl;
    std::cout << "Production year: " << m_year << std::endl;
    std::cout << "Mileage: " << m_mileage << std::endl;
}

void Car::drive(double distance) {
    if(distance < 0) {
        throw 1;
    }
    m_mileage += distance;
}

void Car::service(){
    m_mileage = 0;
}