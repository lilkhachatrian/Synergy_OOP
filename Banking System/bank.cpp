#include "bank.h"

Bank::Bank(Account&& new_account) {
    accounts.push_back(std::move(new_account));
}

void Bank::create_account(size_t account_number, const std::string& name){
    Account prompt(account_number, name);
    accounts.push_back(std::move(prompt));
    std::cout << "Account created!" << std::endl;
}

void Bank::create_account(size_t account_number, const std::string& name, size_t amount){
    Account prompt(account_number, name, amount);
    accounts.push_back(std::move(prompt));
    std::cout << "Account created!" << std::endl; 
}

void Bank::add_account(Account&& new_account){
    accounts.push_back(std::move(new_account));
}

void Bank::deposit_money(size_t account_number, double amount) {
    for(auto &account : accounts){
        if(account.get_account_number() == account_number){
            account.deposit(amount);
            return;
        }
    }
    std::cout << "Account not found." << std::endl;
}

void Bank::withdraw_money(size_t account_number, double amount){
    for(auto &account : accounts){
        if(account.get_account_number() == account_number){
            account.withdraw(amount); 
            return;
        }
    }
    std::cout << "Account not found." << std::endl;
}

void Bank::display_accounts(){
    for(auto &account : accounts){
        account.display_info();
    }
}

Account& Bank::find_account(size_t account_number){
    for(auto &account : accounts){
        if(account.get_account_number() == account_number){
            return account;
        }
    }
    throw 1;
}

void Bank::transfer_money(Account& from, Account& to, size_t amount){
    to.deposit(amount);
    from.withdraw(amount);    
}
