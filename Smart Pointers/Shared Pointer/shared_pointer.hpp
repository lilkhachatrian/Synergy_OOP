#include <iostream>
#include "control_block.hpp"

template <typename T>
class SharedPtr{

private:
    T* m_ptr;
    ControlBlock* m_control_block;
};
