#include "stack.h"


void Stack::free() {
    delete[] data_;
    data_ = nullptr;
    maxsize_ = 0;
}

