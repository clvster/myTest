#pragma once
#include <sstream>
#include <exception>
#include <iostream>


template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint) {
    if (t != u) {
        std::ostringstream os;
        os << "Assertion failed: " << t << " != " << u << ". Hint: " << hint;
        throw std::runtime_error(os.str());
    }
}

void Assert(bool b, const std::string& hint);

class TestRunner {
private:
    int fail_count = 0;

public:
    template <class TestFunc>
    void RunTest(TestFunc func, const std::string& test_name) {
        try {
            func();

            std::cerr << "Test " << test_name << " OK" << std::endl;
        } catch (std::runtime_error& e) {
            std::cerr << "Test " << test_name << " fail. " << e.what() << std::endl;
            ++fail_count;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            std::cerr << fail_count << " tests failed. Terminate" << std::endl;
            exit(1);
        }
    }
};
