#include "test.h"
#include "stack.h"
#include "mytest.h"


void TestStackPush() {
    {
        Stack S(1);
        S.push(1);
        AssertEqual(S.top(), 1, "one element");
    }

    {
        int n = 100;
        Stack S(n);
        for (int i = 0; i < n; ++i) {
            S.push(i);
            AssertEqual(S.top(), i, "i element");
        }
    }

    // std::cout << "TestStackPush OK" << std::endl;
}

void TestStackSize() {
    {
        Stack S(1);
        AssertEqual(S.size(), 0, "size must be zero");
        S.push(1);
        AssertEqual(S.size(), 1, "size must be one");
    }

    {
        int n = 100;
        Stack S(n);
        for (int i = 1; i <= n; ++i) {
            S.push(i);
            AssertEqual(S.size(), i, "label 0");
        }
        AssertEqual(S.size(), n, "label 1");
    }

    // std::cout << "TestStackSize OK" << std::endl;
}

void TestStackEmpty() {
    {
        Stack S(10);
        Assert(S.empty(), "must be empty");
    }

    // std::cout << "TestStackEmpty OK" << std::endl;
}

void TestStackPop() {
    {
        Stack S(1);
        S.push(10);
        S.pop();
        AssertEqual(S.size(), 0, "size must be zero");
        Assert(S.empty(), "must be empty");
    }

    {
        int n = 100;
        Stack S(n);

        for (int i = 0; i < n; ++i) {
            S.push(i + 1);
        }

        for (int i = n; i > 0; --i) {
            AssertEqual(S.top(), i, "top is equal pushed");
            S.pop();
        }

        AssertEqual(S.size(), 0, "size must be zero");
        Assert(S.empty(), "must be empty");
    }

    // std::cout << "TestStackPop OK" << std::endl;
}

void TestStackPushPop() {
    {
        int n = 100;
        Stack S(n);

        for (int i = 0; i < n; ++i) {
            S.push(i);
            S.pop();
            Assert(S.empty(), "must be empty");
        }
    }

    // std::cout << "TestStackPushPop OK" << std::endl;
}


void TestAll() {
    TestRunner tr;
    tr.RunTest(TestStackEmpty, "StackEmpty");
    tr.RunTest(TestStackPush, "StackPush");
    tr.RunTest(TestStackSize, "StackSize");
    tr.RunTest(TestStackPop, "StackPop");
    tr.RunTest(TestStackPushPop, "StackPushPop");
}
