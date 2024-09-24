#include <iostream>
#include <memory>
#include <utility>
#include "allocator.cpp"

int main(){
    Allocator<int> alloc;
    alloc.allocate(10);
}
