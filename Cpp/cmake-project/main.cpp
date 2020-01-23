#include <iostream>

#include "MathFuncsLib.h"

using namespace std;

int main(int argc, char const *argv[])
{
    double a = 7.4;
    int b = 99;

    cout << "a + b = " <<
        MathFuncs::MyMathClass::Add(a,b) << endl;    
    cout << "a - b = " <<
        MathFuncs::MyMathClass::Subtract(a, b) << endl;
    cout << "a * b = " <<
        MathFuncs::MyMathClass::Multiply(a, b) << endl;
    cout << "a / b = " <<
        MathFuncs::MyMathClass::Divide(a, b) << endl;

    return 0;
}
