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
    pointer allocate(size_type count){
        if(count * sizeof(value_type) > N/2){
            return static_cast<pointer>(::operator new(count * sizeof(value_type)));
        }
        if(!m_flag){
            return static_cast<pointer>(reinterpret_cast<void*>(m_storage));
        }
        m_flag = !m_flag;
        return static_cast<pointer>(reinterpret_cast<void*>(m_storage + N/2));
    }
    void deallocate(void* ptr, size_type){
        if(ptr != reinterpret_cast<void*>(m_storage) && ptr != reinterpret_cast<void*>(m_storage + N/2)){
            ::operator delete(ptr);
        }
    }

template <typename ...Args>
void construct(pointer ptr, Args...args){
    std::construct_at(ptr, std::forward<Args>(args)...);
}


void destroy(pointer ptr){
    std::destroy_at(ptr);
}


size_type max_size(){
    return static_cast<size_type>(N) / 2;
}

private:
    bool m_flag = false;
    char m_storage[N];
};