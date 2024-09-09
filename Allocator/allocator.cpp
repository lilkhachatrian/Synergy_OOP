#include "allocator.h"

template <typename T>
Allocator<T>::pointer Allocator<T>::allocate(size_type count){
    if(count * sizeof(value_type) > N/2){
        return static_cast<pointer>(::operator new(count * sizeof(value_type)));
    }
    if(!m_flag){
        return static_cast<pointer>(reinterpret_cast<void*>(m_storage));
    }
    m_flag = !m_flag;
    return static_cast<pointer>(reinterpret_cast<void*>(m_storage + N/2));
}

template <typename T>
void Allocator<T>::deallocate(void* ptr, size_type){
    if(ptr != reinterpret_cast<void*>(m_storage) && ptr != reinterpret_cast<void*>(m_storage + N/2)){
        ::operator delete(ptr);
    }
}

template <typename T>
template <typename ...Args>
void Allocator<T>::construct(pointer ptr, Args...args){
    std::construct_at(ptr, std::forward<Args>(arg)...);
}

template <typename T>
void Allocator<T>::destroy(pointer ptr){
    std::destroy_at(ptr);
}

template <typename T>
Allocator<T>::size_type Allocator<T>::max_size(){
    return static_cast<size_type>(N) / 2;
}
