#pragma once

#include <string>
#include <vector>
#include <chrono>
#include "Account.h"

class Account;

enum TransactionType {
    Deposit,
    Withdrawal
};

class TransactionManager {
public: 
    virtual void log_transaction(TransactionType type, double amount, Account* from) = 0;
    virtual void show_transaction_history() const = 0;
};

class Transaction : public TransactionManager {
public:
    void log_transaction(TransactionType type, double amount, Account* from) override;
    void show_transaction_history() const override;
    void log();
    virtual ~Transaction();

private:
    Account* m_from_account;
    Account* m_to_account;
    double m_amount;
    TransactionType m_transaction_type;
    std::chrono::time_point<std::chrono::system_clock> m_timestamp;
};
