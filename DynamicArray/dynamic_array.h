#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>

class DynamicArray{
private:
    int* m_arr;
    size_t m_size;
    size_t m_cap;

public:
    //constructor and destructor prototypes
    DynamicArray();
    DynamicArray(size_t length);
    DynamicArray(const DynamicArray& rhs);
    DynamicArray(DynamicArray&& rhs) noexcept;
    ~DynamicArray();

    // operator overloading
    DynamicArray& operator=(const DynamicArray& rhs);
    DynamicArray& operator=(DynamicArray&& rhs) noexcept;
    int& operator[](size_t index);

//Getter methods
public:
    size_t size();
    size_t capacity();
    bool empty();
    int& front();
    int& back();

// For modifying content of the array
private:
    void reAllocate(size_t newCapacity);

public:
    void push_back(const int& value);
    void pop_back();
    void erase(size_t index);
    void clear() noexcept;

};

#endif