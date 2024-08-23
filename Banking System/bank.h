#pragma once

#include "account.h"
#include <vector>

/* 
Bank: A class to manage multiple accounts. It includes methods to create new accounts, 
deposit money, withdraw money, and display account details. 
*/

class Bank {
private:
    std::vector<Account> accounts;

public:
   Bank() = default;
   Bank(Account&& new_account);
   Bank(const Bank& other) = delete;
   Bank& operator=(const Bank& other) = delete;
   Bank(Bank&& other) = delete;
   Bank& operator=(Bank&& other) = delete;

public:
    void create_account(size_t account_number, const std::string& name);
    void create_account(size_t account_number, const std::string& name, size_t amount);
    void add_account(Account&& new_account);
    void deposit_money(size_t account_number, double amount);
    void withdraw_money(size_t account_number, double amount);
    void display_accounts();
    Account& find_account(size_t account_number);
    void transfer_money(Account& from, Account& to, size_t amount);
};