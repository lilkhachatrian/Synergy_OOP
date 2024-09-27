#include "my_unique_pointer.hpp"
#include <memory>
#include <iostream>

int main(){
    UniquePtr<int> smart_ptr1(new int);
    UniquePtr<int> smart_ptr2(new int);
    smart_ptr1 = std::move(smart_ptr1);
    //smart_ptr1 = smart_ptr2.release();
}