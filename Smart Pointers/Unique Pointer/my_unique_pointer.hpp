#pragma once

#include <type_traits>
#include <iostream>
#include <cstdint>

template <typename T>
class UniquePtr{
public:
    UniquePtr() : m_ptr(nullptr) {}
    explicit UniquePtr(T* pointer) : m_ptr(pointer) {std::cout << "Ctor with params.\n";}

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& rhs){
        static_assert(std::is_same<decltype(this), decltype(&rhs)>::value, "Types don't match.");
            m_ptr = rhs.m_ptr;
            rhs.m_ptr = nullptr;
            std::cout << "Moved.\n";
    }

    UniquePtr& operator=(UniquePtr&& rhs){
        static_assert(std::is_same<decltype(this), decltype(&rhs)>::value, "Types don't match.");
        if(m_ptr != nullptr) delete m_ptr;
        m_ptr = rhs.m_ptr;
        rhs.m_ptr = nullptr;
        return *this;
    }

    ~UniquePtr() {
        if(m_ptr != nullptr) {
            delete m_ptr;
            std::cout << "Destroyed!\n";
        }
    }

    T* release(){
        T* temp = m_ptr;
        m_ptr = nullptr;
        return temp;
    }

    T& operator*() const {
        return *m_ptr;
    }

    T* operator->() const {
        return m_ptr;
    }

private:
    T* m_ptr;
};

template<typename T, typename ...Args>
UniquePtr<T>& make_unique(Args...args){
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}

template <typename T>
class UniquePtr<T[]> {
public:
    UniquePtr() : m_ptr(nullptr) {}
    explicit UniquePtr(T* pointer) : m_ptr(pointer) {std::cout << "Template spec for array.\n";}

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& rhs){
        static_assert(std::is_same<decltype(this), decltype(&rhs)>::value, "Types don't match.");
        m_ptr = rhs.m_ptr;
        rhs.m_ptr = nullptr;
        std::cout << "Moved[].\n";
    }

    UniquePtr& operator=(UniquePtr&& rhs){
        static_assert(std::is_same<decltype(this), decltype(&rhs)>::value, "Types don't match.");
        if(m_ptr != nullptr) delete m_ptr;
        m_ptr = rhs.m_ptr;
        rhs.m_ptr = nullptr;
        return *this;
    }

    ~UniquePtr() {
    if(m_ptr != nullptr) delete[] m_ptr;
    }

    T& operator[](size_t index) const{
        return m_ptr[index];
    }

private:
    T* m_ptr;
};