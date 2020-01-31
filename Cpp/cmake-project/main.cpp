#include <iostream>

#include "MathFuncsLib.h"
#include "Module1.h"

using namespace std;
using namespace mathfuncs;

int main(int argc, char const *argv[])
{
    double a = 7.4;
    int b = 99;

    cout << "a + b = " <<
        MyMathClass::add(a,b) << endl;    
    cout << "a - b = " <<
        MyMathClass::subtract(a, b) << endl;
    cout << "a * b = " <<
        MyMathClass::multiply(a, b) << endl;
    cout << "a / b = " <<
        MyMathClass::divide(a, b) << endl;

    Module1 m1 = Module1("thisIsMyModuleName");
    cout << "Module name: " <<
        m1.getModuleName() << endl;

    return 0;
}
