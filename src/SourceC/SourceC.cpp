#include "SourceC.hpp"
#include <stdexcept>
#include <iostream>
#include "SourceD.hpp"

// Global variable definition
static int global_temp = 0;
extern int anotherFileGVar;

int SourceC::SetGlobalVar(int tempValue)
{
    global_temp = tempValue;
    return global_temp;
}

int SourceC::temperature()
{
    if (global_temp < 10 && anotherFileGVar < 10) 
    {
        return -1; // Indicating temperature is too low
    } 
    else if (global_temp >= 30 && global_temp <= 100 && anotherFileGVar >= 30 && anotherFileGVar <= 100)
    {
        return 0; // Indicating temperature is in between
    } 
    else 
    {
        return 1; // Indicating temperature is not found in the range
    }
}

double SourceC::VoltageCheck(double i, double R)
{
    double voltage = CalculateVoltage(i, R);
    if(voltage < 0)
    {
        return -1; // volateg is low
    }
    else if(voltage > 50)
    {
        return 1; // voltage is high
    }
    else
    {
        return 0; // voltage is in range
    }

    // return 
}

double SourceC::PowerCheck(double current, double resistance)
{
    double Power = PowerCalculate(current, resistance);
    if (Power < 0)
    {
        return -1; // power is low
    }
    else if (Power > 100)
    {
        return 1; // power is high
    }
    else
    {
        return 0; // power is in range
    }
}



