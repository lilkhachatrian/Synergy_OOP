#include "person.h"

Person::Person(const std::string& name, size_t age) : m_name(name), m_age(age) {}

Person::Person(const std::string& name, size_t age, const std::string& make, const std::string& model) :
    Person(name, age) {
        Car(make, model);
    }

Person::Person(const Person& other) : m_name(other.m_name), m_age(other.m_age) {}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        m_name = other.m_name;
        m_age = other.m_age;
    }
    return *this;
}

Person::Person(Person&& rhs) noexcept : m_name(std::move(rhs.m_name)), m_age(rhs.m_age) {
    rhs.clear();
}

Person& Person::operator=(Person&& rhs) noexcept {
    if (this != &rhs) {
        m_name = std::move(rhs.m_name);
        m_age = rhs.m_age;
        rhs.clear();
    }
    return *this;
}

Person::~Person() {
    clear();
}

void Person::set_name(const std::string& name) {
    m_name = name;
}

void Person::set_age(size_t age) {
    m_age = age;
}

const std::string& Person::get_name() const {
    return m_name;
}

size_t Person::get_age() const {
    return m_age;
}

void Person::clear() {
    m_name.clear();
    m_age = 0;
}
