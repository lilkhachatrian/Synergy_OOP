#pragma once

#include "Account.h"
#include "Transaction.h"
#include <string>
#include <vector>

class Account;

class Customer {
public:
    Customer(const std::string& name, const std::string& contact_info);
    Customer(const std::string& name, const std::string& contact_info, Account* account);
    Customer(const Customer& rhs);
    Customer(Customer&& rhs);
    Customer& operator=(const Customer& rhs);
    Customer& operator=(Customer&& rhs);
    void add_account(Account* account);
    void view_accounts() const;
    void view_transaction_history() const;
    ~Customer();

private:
    std::string m_name;
    std::string m_contact_info;
    std::vector<Account*> m_accounts;
};

