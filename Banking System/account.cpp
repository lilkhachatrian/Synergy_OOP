#include "account.h"

// ctor definitions

Account::Account(size_t account_number, const std::string& name) : Account::Account(account_number, name, 0) {}
Account::Account(size_t account_number, const std::string& name, double balance) : m_account_number(account_number), m_name(name), m_balance(balance) {}
Account::Account(Account&& other) noexcept
    : m_account_number(other.m_account_number), m_name(std::move(other.m_name)), m_balance(other.m_balance) {
        other.m_account_number = 0;
        other.m_balance = 0;
}
Account& Account::operator=(Account&& other) noexcept {
    if(this != &other){
        m_account_number = other.m_account_number;
        m_name = std::move(other.m_name);
        m_balance = other.m_balance;

        other.m_account_number = 0;
        other.m_balance = 0;
    }

    return *this;
}

Account::~Account() {}

// method definitions

void Account::deposit(double amount){
    if(amount > 0) m_balance += amount;
    return;
}

void Account::withdraw(double amount){
    if(amount > 0 && m_balance > amount) m_balance -= amount;
    if(m_balance == 0 || amount > m_balance){
        std::cout << "Insufficiant funds." << std::endl;
    } 
    return;
}

double Account::get_balance() const {
    return m_balance;
}

std::string Account::get_name() const {
    return m_name;
}

size_t Account::get_account_number() const {
    return m_account_number;
}

void Account::display_info(){
    std::cout << "Client name: " << m_name << std::endl;
    std::cout << "Bank account number: " << m_account_number << std::endl;
    std::cout << "Balance: " << m_balance << std::endl;
}
