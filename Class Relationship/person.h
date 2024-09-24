#pragma once

#include <string>
#include "car.cpp"

class Person {
public:
// defining ctors and assignment operators
    Person(const std::string& name, size_t age);
    Person(const std::string& name, size_t age, Car& car);
    Person(const std::string& name, size_t age, const std::string& make, const std::string& model);
    Person(const std::string& name, size_t age, const std::string& make, const std::string& model, size_t year, double mileage);
    Person(const Person& other);
    Person& operator=(const Person& other);
    Person(Person&& rhs) noexcept;
    Person& operator=(Person&& rhs) noexcept;
    ~Person();

// setter and getter methods
    void set_name(const std::string& name);
    void set_age(size_t age);
    const std::string& get_name() const;
    size_t get_age() const;
    void clear();

// including Car object in the class

// data members
private:
    std::string m_name;
    size_t m_age;
    Car m_car;
};
