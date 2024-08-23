#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {
private:
    size_t m_account_number;
    std::string m_name;
    double m_balance;

public:
    Account(size_t account_number, const std::string& name);
    Account(size_t account_number, const std::string& name, double balance);
    Account(Account&& other) noexcept;
    Account& operator=(Account&& other) noexcept;
    ~Account();
    Account(const Account&) = delete;
    Account& operator=(const Account&) = delete;

public:
    void deposit(double amount);
    void withdraw(double amount);
    double get_balance() const;
    std::string get_name() const;
    size_t get_account_number() const;
    void display_info();
};

#endif