#ifndef SOURCEC_HPP
#define SOURCEC_HPP

class SourceC {
public:
    static int SetGlobalVar(int tempValue);
    static int temperature();
    static double VoltageCheck(double i, double R);
    static double PowerCheck(double current, double resistance);
};

#endif