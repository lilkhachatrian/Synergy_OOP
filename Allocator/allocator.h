#pragma once

const int N = 3000;

template <typename T>
class Allocator{
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = size_t;

public:
    pointer allocate(size_type count);
    void deallocate(void*, size_type);
    template <typename ...Args>
    void construct(pointer ptr, Args...args);
    void destroy(pointer ptr);
    size_type max_size();

private:
    bool m_flag = false;
    char m_storage[N];
};
