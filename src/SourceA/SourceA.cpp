#include "SourceA.hpp"
//#include "SourceB.hpp"
#include <stdexcept>

int SourceA::sum(int x, int y) {
    SourceB b;
    return b.doubleValueB(x) + b.doubleValueB(y);
}

int SourceA::multiply(int x, int y) {
    return x * y;
}

double SourceA::divide(int x, int y) {
    if (y == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return static_cast<double>(x) / y;
}

int SourceA::UsedFunctionB(int x) {
    SourceB b;
    return b.doubleValueB(x);
}


