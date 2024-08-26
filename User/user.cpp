#include "user.h"
#include <stdexcept>

// ctor with parameters
User::User(const std::string& fullName, const std::string& email, const std::string& password) : m_fullname(fullName) {
    if(verify_email_params(email)){
        m_email = email;
    }
    else{
        throw std::invalid_argument("Invalid email address.");
    }
    if(verify_password_params(password)){
        m_password = password;
    }
    else {
        throw std::invalid_argument("Please use 1 upper/lower case letter, 1 number and 1 special character.");
    }
}

// move ctor and move assignment operator
User::User(User&& other) noexcept {
    m_fullname = other.m_fullname;
    m_email = other.m_email;
    m_password = other.m_password;

    other.m_email = "";
    other.m_password = "";
    other.m_fullname = "";
}

User& User::operator=(User&& other) noexcept {
    if(this != &other){
        m_fullname = other.m_fullname;
        m_email = other.m_email;
        m_password = other.m_password;

        other.m_email = "";
        other.m_password = "";
        other.m_fullname = "";
    }
    return *this;
}

// setter methods
void User::set_name(const std::string& name){
    m_fullname = name;
}
void User::set_email(const std::string& email){
    if(verify_email_params(email)){
        m_email = email;
        std::cout << "Email is set successfully!" << std::endl;
    }
    else{
        std::cout << "Invalid email." << std::endl;
    }
}

void User::set_password(const std::string& password){
    if(verify_email_params(password)){
        m_password = password;
        std::cout << "Password is set succesfully!" << std::endl;
    }
    else{
        throw std::invalid_argument("Please use 1 upper/lower case letter, 1 number and 1 special character.");
    }
}

// getter methods
std::string User::get_name() const{
    return m_fullname;
}
std::string User::get_password() const{
    return m_password;
}
std::string User::get_email() const{
    return m_email;
}

// member functions to modify private member variables
void User::change_password(const std::string& old_password){
    if(old_password.compare(m_password) != 0){
        std::string new_password;
        std::cout << "Insert new password: ";
        std::getline(std::cin, new_password);
        if(verify_password_params(new_password)){
            m_password = new_password;
            std::cout << "Password is successfully changed!" << std::endl;
        }
        else{
            std::cout << "Please use 1 upper case letter and 1 special character." << std::endl;
        }
    }
}

void User::change_email(const std::string& new_email){
    if(verify_email_params(new_email)){
        m_email = new_email;
    }
    else{
        throw std::invalid_argument("Invalid email address.");
    }
}

void User::change_name(const std::string& new_name){
    m_fullname = new_name;
}

// private member functions to checking email and password verification for avoiding code repeatition
bool User::verify_email_params(const std::string& email){
    for(char c : email){
        if(c == '@') return 1;
    }
    return 0;
}
bool User::verify_password_params(const std::string& password){
    bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_special_character = false;

    if(password.length() >= 8) {
        for(char c : password){
            if(c >= 'A' && c <= 'Z') has_uppercase = true;
            if(c >= 'a' && c <= 'z') has_lowercase = true;
            if(c >= '!' && c <= '@') has_special_character = true; 
        }
    }
    if(has_lowercase && has_uppercase && has_special_character) return 1;
    return 0;
}
