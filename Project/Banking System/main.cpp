#include "../Header/Account.h"
#include "../Header/Customer.h"
#include "../Header/Transaction.h"
#include <iostream>

int main(){
    std::vector<Account*> accounts;
    CheckingAccount n1(500);
    SavingsAccount n3(400);
    CheckingAccount n4(60);
    accounts.push_back(&n1);
    accounts.push_back(&n3);
    accounts.push_back(&n4);


    accounts[2]->deposit(40);
    accounts[2]->show_balance();
    int t = accounts[1]->get_account_type();
    std::cout << t;

}
