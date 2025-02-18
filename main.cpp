#include <iostream>
#include <cassert>
#include "stack.h"
#include "test.h"


int main() {
#ifndef NDEBUG
    TestAll();
#endif

    std::cout << "size: ";
    int n;
    std::cin >> n;
    assert(n > 0);
    Stack S(n);

    // Добавление эл-в в стек
    for (int i = 0; i < n; ++i) {
        S.push(i + 1);
    }

    // Извлечение эл-в из стека
    while (!S.empty()) {
        std::cout << S.top() << " ";
        S.pop();
    }

    std::cout << "\n";

    return 0;
}
