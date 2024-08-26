#include "user.cpp"
#include <typeinfo>

std::string prompt_name();
std::string prompt_email();
std::string prompt_password();

//prototype for typechecking
template <typename T, typename S>
bool type_check(const T& obj1, const S& obj2);

int main(){
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

    User user2 ("Lilit", "@yahoo.com", "Elak1234!");
    User user3("Lilit", "@gmail.com", "Banan1234!");
    std::cout << type_check(user2, user3) << std::endl;
}

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

template <typename T, typename S>
bool type_check(const T& obj1, const S& obj2){
    const std::type_info& type_name1 = typeid(obj1);
    const std::type_info& type_name2 = typeid(obj2);
    return type_name1 == type_name2;
}
