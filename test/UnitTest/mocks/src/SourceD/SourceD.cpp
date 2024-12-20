#include "SourceD.hpp"

int anotherFileGVar = 0;

double (*CalculateVoltagePtr)(double, double) = /*MockCalculateVoltage*/CalculateVoltage;

double /*MockCalculateVoltage*/CalculateVoltage(double current, double resistance) {
    if (resistance == 0) {
        throw std::invalid_argument("Resistance cannot be zero.");
    }
    return current * resistance;
}

// double CalculateVoltage(double current, double resistance) {
//     return CalculateVoltagePtr(current, resistance);
// }   

double (*CalculatePowerPtr)(double, double) = MockCalculatePower;

double MockCalculatePower(double current, double resistance) {
    if (resistance == 0) {
        throw std::invalid_argument("Resistance cannot be zero.");
    }
    return current * current * resistance;
}

double PowerCalculate(double current, double resistance) {
    return CalculateVoltagePtr(current, resistance);
}


