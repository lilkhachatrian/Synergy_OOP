#include "Account.h"
#include "iostream"

int Account::m_account_number_prompt = 20050000;

// account ctor records a default account number with each instantiation
Account::Account(double balance, AccountType type) 
    : m_balance(balance), m_type(type) {
    m_account_number = m_account_number_prompt;
    m_account_number_prompt++;
}

Account::Account(Account&& rhs) 
    : m_account_number(rhs.m_account_number), m_balance(rhs.m_balance),
    m_type(rhs.m_type) {
        rhs.m_account_number = 0;
        rhs.m_balance = 0;
    }

Account& Account::operator=(Account&& rhs) {
    if(this != &rhs){
        m_balance = rhs.m_balance;
        m_account_number = rhs.m_account_number;
        m_type = rhs.m_type;

        rhs.m_account_number = 0;
        rhs.m_balance = 0;
    }
    return *this;
}

int Account::get_account_number() const {
    return m_account_number;
}

Account::~Account() {}

CheckingAccount::CheckingAccount(double balance) 
    : Account(balance, AccountType::Checking) {}

CheckingAccount::CheckingAccount(CheckingAccount&& rhs) 
    : Account(std::move(rhs)) {
        m_overdraft_limit = rhs.m_overdraft_limit;
        rhs.m_overdraft_limit = 0;
    }

CheckingAccount& CheckingAccount::operator=(CheckingAccount&& rhs) {
    if(this != &rhs){
        m_balance = rhs.m_balance;
        m_account_number = rhs.m_account_number;
        m_type = rhs.m_type;
        m_overdraft_limit = rhs.m_overdraft_limit;

        rhs.m_account_number = 0;
        rhs.m_balance = 0;
        rhs.m_overdraft_limit = 0;
    }
    return *this;
}

void CheckingAccount::deposit(double amount) {
    if(amount > 0 ) {
        m_balance += amount;
        std::cout << "Deposited: $" << amount << " to Checking Account " << m_account_number << std::endl;
    }
    else {
        std::cout << "Canceling request." << std::endl;
    }
}

void CheckingAccount::withdraw(double amount) {
    if(amount <= m_overdraft_limit + m_balance){
        m_balance -= amount;
        std::cout << "Withdrew: $" << amount << " from Checking Account " << m_account_number << std::endl;
    }
    else {
        std::cout << "Insufficient funds." << std::endl;
    }
}

void CheckingAccount::transfer(Account& destination, double amount) {
    if(amount <= m_overdraft_limit + m_balance){
        m_balance -= amount;
        destination.deposit(amount);
        std::cout << "Transfered $" << amount << std::endl;
    }
    else {
        std::cout << "Insufficient funds." << std::endl;
    }
}

void CheckingAccount::show_balance() {
    std::cout << "Account Balance: $" << m_balance << std::endl;
}

AccountType CheckingAccount::get_account_type() {
    return m_type;
}
CheckingAccount::~CheckingAccount(){}

SavingsAccount::SavingsAccount(double balance) : Account(balance, AccountType::Savings) {}
SavingsAccount::SavingsAccount(SavingsAccount&& rhs) 
 : Account(std::move(rhs)) {
    m_interest_rate = rhs.m_interest_rate;
 }
SavingsAccount& SavingsAccount::operator=(SavingsAccount&& rhs) {
    if(this != &rhs){
        m_account_number = rhs.m_account_number;
        m_balance = rhs.m_balance;

        rhs.m_account_number = 0;
        rhs.m_balance = 0;
    }
    return *this;
 }

void SavingsAccount::deposit(double amount) {
    if(amount > 0 ) {
        m_balance = amount;
        std::cout << "Deposited: $" << amount << " to Savings Account " << m_account_number << std::endl;
    }
    else {
        std::cout << "Canceling request." << std::endl;
    }
}

void SavingsAccount::withdraw(double amount) {
    if(amount <= m_balance){
        m_balance -= amount;
        std::cout << "Withdrew: $" << amount << " from Savings Account " << m_account_number << std::endl;
    }
    else {
        std::cout << "Insufficient funds." << std::endl;
    }
}

void SavingsAccount::transfer(Account& destination, double amount) {
    if(amount <= m_balance){
        m_balance -= amount;
        destination.deposit(amount);
        std::cout << "Transfered $" << amount << std::endl;
    }
    else {
        std::cout << "Insufficient funds." << std::endl;
    }
}

void SavingsAccount::show_balance() {
    std::cout << "Account Balance: $" << m_balance << std::endl;
}

AccountType SavingsAccount::get_account_type() {
    return m_type;
}
SavingsAccount::~SavingsAccount(){}

JointAccount::JointAccount(double balance) : Account(balance, AccountType::Joint) {}
JointAccount::JointAccount(JointAccount&& rhs) 
 : Account(std::move(rhs)), m_joint_owners(std::move(rhs.m_joint_owners)){
}

JointAccount& JointAccount::operator=(JointAccount&& rhs) {
    if(this != &rhs){
        m_account_number = rhs.m_account_number;
        m_balance = rhs.m_balance;
        m_joint_owners.clear();
        m_joint_owners = std::move(rhs.m_joint_owners);

        rhs.m_account_number = 0;
        rhs.m_balance = 0;
    }
    return *this;
}

void JointAccount::deposit(double amount) {
    if(amount > 0 ) {
        m_balance = amount;
        std::cout << "Deposited: $" << amount << " to Joint Account " << m_account_number << std::endl;
    }
    else {
        std::cout << "Canceling request." << std::endl;
    }
}

void JointAccount::withdraw(double amount) {
    if(amount <= m_balance){
        m_balance -= amount;
        std::cout << "Withdrew: $" << amount << " from Joint Account " << m_account_number << std::endl;
    }
    else {
        std::cout << "Insufficient funds." << std::endl;
    }
}

void JointAccount::transfer(Account& destination, double amount) {
    if(amount <= m_balance){
        m_balance -= amount;
        destination.deposit(amount);
        std::cout << "Transfered $" << amount << std::endl;
    }
    else {
        std::cout << "Insufficient funds." << std::endl;
    }
}

void JointAccount::show_balance() {
    std::cout << "Account Balance: $" << m_balance << std::endl;
}

AccountType JointAccount::get_account_type() {
    return m_type;
}

JointAccount::~JointAccount(){}

void JointAccount::add_account(Customer* account) {
    m_joint_owners.push_back(account);
    std::cout << "Added customer to Joint Account." << std::endl;
}
