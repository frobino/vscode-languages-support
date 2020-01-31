#include <Module1.h>

Module1::Module1(string moduleName)
{
    fModuleName = moduleName;
}

Module1::~Module1()
{
}

string Module1::getModuleName(){
    return fModuleName;
}