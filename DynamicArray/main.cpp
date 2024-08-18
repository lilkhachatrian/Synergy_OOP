#include "dynamic_array.cpp"

int main(){
    DynamicArray vector(4);
    vector.push_back(2);
    std::cout << vector[0] << std::endl;
}