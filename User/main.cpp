#include "user.cpp"
#include <typeinfo>

std::string prompt_name(){
    std::cout << "Full name: ";
    std::string name_prompt;
    std::getline(std::cin, name_prompt);
    return name_prompt;
}

std::string prompt_email(){
    std::cout << "Email: ";
    std::string email_prompt;
    std::getline(std::cin, email_prompt);
    return email_prompt;
}

std::string prompt_password(){
    std::cout << "Password: ";
    std::string password_prompt;
    std::getline(std::cin, password_prompt);
    return password_prompt;
}

int main(){

    // std::cout << "Full name: ";
    // std::getline(std::cin, fullname_prompt);
    // std::cout << "Email: ";
    // std::getline(std::cin, email_prompt);
    // std::cout << "Password: ";
    // std::getline(std::cin, password_prompt);
    
    while(true){
        try {
            std::string fullname_prompt = prompt_name();
            std::string email_prompt = prompt_email();
            std::string password_prompt = prompt_password();
            User user1(fullname_prompt, email_prompt, password_prompt);
            break;
        }
        catch(std::invalid_argument& e){
            std::cout << e.what() << std::endl;
        }
    }
    
    //const std::type_info& type_name = typeid(user1);
    //std::cout << type_name << std::endl;
}
