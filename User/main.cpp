#include "user.cpp"
#include <typeinfo>


int main(){
    std::string fullname_prompt;
    std::string email_prompt;
    std::string password_prompt;

    std::cout << "Full name: ";
    std::getline(std::cin, fullname_prompt);
    std::cout << "Email: ";
    std::getline(std::cin, email_prompt);
    std::cout << "Password: ";
    std::getline(std::cin, password_prompt);

    User user1(fullname_prompt, email_prompt, password_prompt);
    
    //const std::type_info& type_name = typeid(user1);
    //std::cout << type_name << std::endl;
}