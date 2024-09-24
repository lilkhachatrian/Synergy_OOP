#pragma once
#include <vector>
#include <string>
#include "Customer.h"

class Customer;

enum AccountType {
    Checking,
    Savings,
    Joint
};

class Account {
public:
    Account(double balance, AccountType type);
    Account(const Account&) = delete;
    Account& operator=(const Account&) = delete;
    Account(Account&&);
    Account& operator=(Account&&);
    virtual void deposit(double) = 0;
    virtual void withdraw(double) = 0;
    virtual void transfer(Account&, double) = 0;
    virtual void show_balance() = 0;
    virtual AccountType get_account_type() = 0;
    virtual int get_account_number() const;
    virtual ~Account();

private:
    static int m_account_number_prompt;

protected:
    int m_account_number;
    double m_balance;
    AccountType m_type;
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double balance);
    CheckingAccount(const CheckingAccount& rhs) = delete;
    CheckingAccount(CheckingAccount&& rhs);
    CheckingAccount& operator=(const CheckingAccount& rhs) = delete;
    CheckingAccount& operator=(CheckingAccount&& rhs);
    virtual ~CheckingAccount();

    void deposit(double) override;
    void withdraw(double) override;
    void transfer(Account&, double) override;
    void show_balance() override;
    AccountType get_account_type() override;

private:
    double m_overdraft_limit = m_balance * 0.05;
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double balance);
    SavingsAccount(const SavingsAccount& rhs) = delete;
    SavingsAccount(SavingsAccount&& rhs);
    SavingsAccount& operator=(const SavingsAccount& rhs) = delete;
    SavingsAccount& operator=(SavingsAccount&& rhs);
    virtual ~SavingsAccount();

    void deposit(double) override;
    void withdraw(double) override;
    void transfer(Account&, double) override;
    void show_balance() override;
    AccountType get_account_type() override;

private:
    double m_interest_rate = 0.004;
};

class JointAccount : public Account {
public:
    JointAccount(double balance);
    JointAccount(const JointAccount&) = delete;
    JointAccount(JointAccount&&);
    JointAccount& operator=(const JointAccount&) = delete;
    JointAccount& operator=(JointAccount&&);
    virtual ~JointAccount();

    void deposit(double) override;
    void withdraw(double) override;
    void transfer(Account&, double) override;
    void show_balance() override;
    AccountType get_account_type() override;
    void add_account(Customer*);

private:
    std::vector<Customer*> m_joint_owners;
};