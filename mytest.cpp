#include "mytest.h"


void Assert(bool b, const std::string& hint) {
    AssertEqual(b, true, hint);
}