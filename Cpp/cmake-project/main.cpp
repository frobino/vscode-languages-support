#include <iostream>

#include "MathFuncsLib.h"

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

    return 0;
}
