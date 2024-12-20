// #include <gtest/gtest.h>
// #include "SourceD.hpp"
// #include "SourceC.hpp"


// extern int anotherFileGVar;

// TEST(SourceCTest, TemperatureTooLow) {
//     SourceC c;
//     int temp_value = 25;
//     c.SetGlobalVar(temp_value);
//     anotherFileGVar = 15;
//     int result = c.temperature();
//     EXPECT_EQ(result, -1); // Expect -1 for too low temperature
// }

// TEST(SourceCTest, TemperatureNotFoundInRange) {
//     SourceC c;
//     int temp_value = 101;
//     c.SetGlobalVar(temp_value);
//     anotherFileGVar = 105;
//     int result = c.temperature();
//     EXPECT_EQ(result, 1); // Expect 1 for temperature not found in the range
// }

// TEST(SourceCTest, VoltageTooLow) {
//     SourceC c;
//     double current = 0.5;
//     double resistance = 0.0;
//     double res = c.VoltageCheck(current, resistance);
//     EXPECT_EQ(result, -1); // Expect -1 for too low voltage
// }   

// TEST(SourceCTest, VoltageIsHigh {
//     SourceC c;
//     double current = 0.5;
//     double resistance = 0.0;
//     double res = c.VoltageCheck(current, resistance);
//     EXPECT_EQ(result, -1); // Expect -1 for too low voltage
// }   

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }




#include "SourceC.hpp"
#include "SourceD.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Return;
using ::testing::Throw;

// extern double (*CalculateVoltagePtr)(double, double);
// extern double MockCalculateVoltage(double, double);

class SourceC_Test : public ::testing::Test {
protected:
    void SetUp() override {
        // Point the function pointer to the mock function
        // CalculateVoltagePtr = MockCalculateVoltage;
        // CalculatePowerPtr = MockCalculatePower;
        CalculateVoltagePtr = CalculateVoltage;
    }

    void TearDown() override {
        // Reset the function pointer if needed
        CalculateVoltagePtr = nullptr;
        CalculatePowerPtr = nullptr;

    }
};

TEST_F(SourceC_Test, VoltageChecktooLow) {
    SourceC c;
    double res = c.VoltageCheck(1.0, 1.0);    
    EXPECT_EQ(res, 0);
}

TEST_F(SourceC_Test, VoltageCheckTooHigh) {
    SourceC c;
    double res = c.VoltageCheck(50, 3);    
    EXPECT_EQ(res, 1);
}

TEST_F(SourceC_Test, TemperatureTest) {
    anotherFileGVar = 5;
    SourceC c;
    c.SetGlobalVar(5);
    int result = c.temperature();
    EXPECT_EQ(result, -1);
}

TEST_F(SourceC_Test, TemperatureNotFoundInRange) {
    SourceC c;
    int temp_value = 101;
    c.SetGlobalVar(temp_value);
    anotherFileGVar = 105;
    int result = c.temperature();
    EXPECT_EQ(result, 1); // Expect 1 for temperature not found in the range
}

TEST_F(SourceC_Test, PowerCheck) {
    SourceC c;
    double res = c.PowerCheck(2.0, 7.0);    
    EXPECT_EQ(res, 0);
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



