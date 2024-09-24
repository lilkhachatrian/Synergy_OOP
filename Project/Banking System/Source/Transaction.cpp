#include "Transaction.h"
#include <iostream>


void Transaction::log_transaction(TransactionType type, double amount, Account* from) {
    m_transaction_type = type;
    m_amount = amount;
    m_timestamp = std::chrono::system_clock::now();
    if(type == TransactionType::Deposit) {
        from->deposit(amount);
        std::cout << "Logged deposit transaction $" << amount << std::endl;
    }
    else{
        from->withdraw(amount);
        std::cout << "Logged withdrawal transaction $" << amount << std::endl;
    }
}

void Transaction::show_transaction_history() const {
    
}

Transaction::~Transaction(){}