#pragma once
#include <cassert>


struct Stack {
private:
    int maxsize_;
    int* data_;
    int size_;

public:
    Stack(int size) {
        assert(size > 0);

        maxsize_ = size;
        data_ = new int[size];
        size_ = 0;
    }

    void push(int x) {
        assert(size_ < maxsize_);
        data_[size_] = x;
        ++size_;
    }

    void pop() {
        --size_;
        assert(size_ >= 0);
    }

    int top() {
        assert(size_ > 0);
        return data_[size_ - 1];
    }

    bool empty() {
        return size_ == 0;
    }

    int size() {
        return size_;
    }

    void free();

    ~Stack() {
        free();
        // delete[] data_;
    }
};
