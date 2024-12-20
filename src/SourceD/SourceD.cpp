#include "SourceD.hpp"
#include <stdexcept>
#include <iostream>

int anotherFileGVar = 0;
static int current = 0;
// int SourceD::SetanotherGlobalVar(int globalVar)
// {
//     anotherFileGVar = globalVar;
//     return anotherFileGVar;
// }

double CalculateVoltage(double current, double resistance)
{
    if (resistance == 0) {
        throw std::invalid_argument("Resistance cannot be zero.");
    }
    return current * resistance;
}

static double PowerCalculate(double current, double resistance)
{
    return current * current * resistance;
}

