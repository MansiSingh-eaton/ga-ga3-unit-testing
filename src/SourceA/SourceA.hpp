#ifndef SOURCE_A_HPP
#define SOURCE_A_HPP
#include "SourceB.hpp"

class SourceA {
public:
   static int sum(int a, int b);
   static int multiply(int a, int b);
   static double divide(int a, int b);
   static int UsedFunctionB(int x);
};

#endif // SOURCE_A_HPP
