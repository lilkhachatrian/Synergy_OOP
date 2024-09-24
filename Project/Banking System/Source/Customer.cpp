#include "Customer.h"
#include <iostream>
#include <algorithm>

Customer::Customer(const std::string& name, const std::string& contact_info) 
    : m_name(name), m_contact_info(contact_info) {}
Customer::Customer(const std::string& name, const std::string& contact_info, Account* account) 
    : Customer(name, contact_info) {
    m_accounts.push_back(account);
}

Customer::Customer(const Customer& rhs) 
    : m_name(rhs.m_name), m_contact_info(rhs.m_contact_info), m_accounts(rhs.m_accounts) {}

Customer::Customer(Customer&& rhs) 
    : m_name(std::move(rhs.m_name)), m_contact_info(std::move(rhs.m_contact_info)), m_accounts(std::move(rhs.m_accounts)) {
        rhs.m_accounts.clear();
    }

Customer& Customer::operator=(const Customer& rhs){
    if(this != &rhs){
        m_name = rhs.m_name;
        m_contact_info = rhs.m_contact_info;
        m_accounts = rhs.m_accounts;
    }
    return *this;
}

Customer& Customer::operator=(Customer&& rhs){
    if(this != &rhs){
        m_name = std::move(rhs.m_name);
        m_contact_info = std::move(rhs.m_contact_info);
        m_accounts = std::move(rhs.m_accounts);
        rhs.m_accounts.clear();
    }
    return *this;
}

void Customer::add_account(Account* account){
    if (std::find(m_accounts.begin(), m_accounts.end(), account) != m_accounts.end()) {
        std::cout << "Account is already added." << std::endl;
        return;
    };
    m_accounts.push_back(account);
}

void Customer::view_accounts() const {
    for(auto account : m_accounts){
        if(account){
            std::cout << account->get_account_number() << std::endl;
        }
    }
}

void Customer::view_transaction_history() const {

}

Customer::~Customer(){} 
