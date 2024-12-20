// #ifndef SOURCEDMOCK_HPP
// #define SOURCEDMOCK_HPP

// #include <gmock/gmock.h>
// #include <stdexcept>
// #include <iostream>

// int anotherFileGVar = 0;

// double MockCalculateVoltage(double current, double resistance)
// {
//     if (resistance == 0) {
//         throw std::invalid_argument("Resistance cannot be zero.");
//     }
//     return current * resistance; // Return a calculated value based on inputs
// }

// // Use a function pointer to redirect calls to the mock function
// double (*CalculateVoltagePtr)(double, double) = MockCalculateVoltage;

// // Redirect the original function to the mock function
// double CalculateVoltage(double current, double resistance)
// {
//     return CalculateVoltagePtr(current, resistance);
// }




// // class SourceD_MOCK {
// // public:
// //     MOCK_METHOD(int, SetanotherGlobalVar, (int));
// // };

// // class SourceD {
// // public:
// //     SourceD() {}
// //     static void SetMock(SourceD_MOCK* _mock) {
// //         mock = _mock;
// //     }

// //     static int SetanotherGlobalVar(int globalVar) {
// //         if (mock == nullptr) {
// //             throw std::runtime_error("Mock object not set");
// //         }
// //         return mock->SetanotherGlobalVar(globalVar);
// //     }

// // private:
// //     static SourceD_MOCK* mock;
// // };

// // SourceD_MOCK* SourceD::mock = nullptr;

// // double CalculateVoltage(double current, double resistance) {
// //     if (resistance == 0) {
// //         throw std::invalid_argument("Resistance cannot be zero.");
// //     }
// //     return current * resistance;
// // }

// #endif // SOURCED_HPP#include <gtest/gtest.h>


#ifndef SOURCEDMOCK_HPP
#define SOURCEDMOCK_HPP

#include <stdexcept>

extern int anotherFileGVar;

extern double (*CalculateVoltagePtr)(double, double);

double MockCalculateVoltage(double current, double resistance);

double CalculateVoltage(double current, double resistance);

extern double (*CalculatePowerPtr)(double, double);

double MockCalculatePower(double current, double resistance);

double PowerCalculate(double current, double resistance);

 #endif // SOURCED_HPP