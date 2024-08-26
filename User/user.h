#pragma once

#include <iostream>
#include <string>

class User {
public:
    User(const std::string& fullName, const std::string& email, const std::string& password);
    User(const User& other) = delete;
    User& operator=(const User& other) = delete;
    User(User&& other) noexcept;
    User& operator=(User&& other) noexcept;

public:
    void set_name(const std::string& name);
    void set_email(const std::string& email);
    void set_password(const std::string& password);
    std::string get_name() const;
    std::string get_password() const;
    std::string get_email() const;

public:
    void change_password(const std::string& old_password);
    void change_email(const std::string& new_email);
    void change_name(const std::string& new_name);
    
private:
    bool verify_password_params(const std::string& password);
    bool verify_email_params(const std::string& email);

private:
    std::string m_fullname;
    std::string m_email;
    std::string m_password;
};