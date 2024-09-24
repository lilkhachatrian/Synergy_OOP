#include "animal.h"
#include <iostream>

void Dog::make_sound(){
    std::cout << "Bark!" << std::endl;
}

void Cat::make_sound(){
    std::cout << "Meow!" << std::endl;
}

void Cow::make_sound(){
    std::cout << "Moo!" << std::endl;
}
