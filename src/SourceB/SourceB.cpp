#include "SourceB.hpp"
#include <stdexcept>

int SourceB::doubleValueB(int x) {
    return x * 2; 
}

int SourceB::tripleValue(int x) {
    return x * 3;
}

bool SourceB::isPositive(int x) {
    return x > 0;
}

int SourceB::factorial(int x) {
    if (x < 0) {
        throw std::invalid_argument("Negative number");
    }
    int result = 1;
    for (int i = 1; i <= x; ++i) {
        result *= i;
    }
    return result;
}
