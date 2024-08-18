#include "dynamic_array.h"

//implementing ctors and dtor
DynamicArray::DynamicArray() : m_arr(nullptr), m_size(0), m_cap(0){
    reAllocate(2);
}
DynamicArray::DynamicArray(size_t length) : m_size(0), m_cap(length * 2){
    m_arr = new int[m_cap];
    for (size_t i = 0; i < m_cap; ++i) {
        m_arr[i] = 0; 
    }
}
DynamicArray::DynamicArray(const DynamicArray& rhs) : m_size(rhs.m_size), m_cap(rhs.m_cap), m_arr(new int[rhs.m_cap]) {
    for(size_t i = 0; i < m_size; ++i){
        this->m_arr[i] = rhs.m_arr[i];
    }
}

DynamicArray::DynamicArray(DynamicArray&& rhs) noexcept
    : m_size(rhs.m_size), m_cap(rhs.m_cap), m_arr(rhs.m_arr) {
    rhs.m_size = 0;
    rhs.m_cap = 0;
    rhs.m_arr = nullptr;
}

DynamicArray::~DynamicArray(){
    clear();
}

// copy and move assignment operators
DynamicArray& DynamicArray::operator=(const DynamicArray& rhs){
    if(this != &rhs){
        clear();
        m_size = rhs.m_size;
        m_cap = rhs.m_cap;
        m_arr = new int[m_cap];
        for(size_t i = 0; i < m_size; ++i){
            m_arr[i] = rhs.m_arr[i];
        }
    }
    return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& rhs) noexcept {
    if(this != &rhs){
        clear();
        m_size = rhs.m_size;
        m_cap = rhs.m_cap;
        m_arr = rhs.m_arr;

        rhs.m_size = 0;
        rhs.m_cap = 0;
        rhs.m_arr = nullptr;
    }
    return *this;
}

// subscript operator
int& DynamicArray::operator[](size_t index){
    if(index < 0) throw 1;
    return m_arr[index];
}

//Getter methods
size_t DynamicArray::size(){
    return m_size;
}
size_t DynamicArray::capacity(){
    return m_cap;
}
bool DynamicArray::empty(){
    if(m_size == 0) return 1;
    return 0;
}
int& DynamicArray::front(){
    return m_arr[0];
}
int& DynamicArray::back(){
    return m_arr[m_size - 1];
}

// modyfying array content
void DynamicArray::reAllocate(size_t newCapacity){
    int* new_arr = new int[newCapacity];
    for(size_t i = 0; i < m_size; ++i){
        new_arr[i] = m_arr[i];
    }
    delete[] m_arr;
    m_arr = new_arr;
    new_arr = nullptr;
    m_cap = newCapacity;
}

void DynamicArray::push_back(const int& value){
    if(m_size >= m_cap) reAllocate(m_cap * 2);
    m_arr[m_size] = value;
    m_size++;
}

void DynamicArray::pop_back(){
    if(m_size == 0) return;
    m_size--;
}

void DynamicArray::erase(size_t index){
    if(index >= m_size && index < 0) {
        std::cout << "Out of range." << std::endl;
    }
    for(size_t i = index; i < m_size; ++i){
        m_arr[i] = m_arr[i + 1];
    }
    --m_size;
}
void DynamicArray::clear() noexcept{
    m_size = 0;
    m_cap = 0;
    delete[] m_arr;
    m_arr = nullptr;
}
