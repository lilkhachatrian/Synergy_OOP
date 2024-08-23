#include "account.cpp"
#include "bank.cpp"

Bank bank;
size_t account_prompt = 21001;
std::string name_prompt;
double balance_prompt = 0;

int main(){

    size_t count = 0;
    std::cout << "Welcome! Please insert the number of accounts you want to create: ";
    std::cin >> count;
    
    while(count){
        std::cout << "Insert account holder's name: ";
        std::cin >> name_prompt;
        std::cout << "Insert account balance: ";
        std::cin >> balance_prompt;
        Account prompt_acc(account_prompt, name_prompt, balance_prompt);
        bank.add_account(std::move(prompt_acc));
        account_prompt++;
        count--;
    }
    
    bank.display_accounts();

    int choice = 0;
    std::cout << "Please choose desired operation." << std:: endl;
    std::cout << "*Press 1 for creating new account*" << std::endl;
    std::cout << "*Press 2 for money deposit*" << std::endl;
    std::cout << "*Press 3 for money withdrawal*" << std::endl;
    std::cin >> choice;

    switch (choice) {
        case 1: 
        std::cout << "Insert account holder's name: ";
        std::cin >> name_prompt;
        std::cout << "Insert account balance: ";
        std::cin >> balance_prompt;
        account_prompt++;
        bank.create_account(account_prompt, name_prompt, balance_prompt);
        break;

        case 2:
        std::cout << "Insert account number: ";
        std::cin >> account_prompt;
        std::cout << "Amount of money: ";
        std::cin >> balance_prompt;
        bank.deposit_money(account_prompt, balance_prompt);
        break;

        case 3:
        std::cout << "Insert account number: ";
        std::cin >> account_prompt;
        std::cout << "Amount of money: ";
        std::cin >> balance_prompt;
        bank.withdraw_money(account_prompt, balance_prompt);
        break;

        default:
        std::cout << "Operation terminated." << std::endl;
    }    

    choice = 0;
    std::cout << "For transfering money press 1, for exiting press 2: ";
    std::cin >> choice;

    if(choice == 1){
        std::cout << "Please insert account number for transfering from: ";
        size_t acc1 = 0;
        std::cin >> acc1;
        std::cout << "Insert account number for transfering money: ";
        size_t acc2 = 0;
        std::cin >> acc2;
        double amount = 0;
        std::cout << "Transferable amount: ";
        std::cin >> amount;
        bank.transfer_money(bank.find_account(acc1), bank.find_account(acc2), amount);
    }

    bank.display_accounts();
}