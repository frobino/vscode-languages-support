#include <string>

using namespace std;

class Module1
{
private:
    string fModuleName;
public:
    Module1(string moduleName);
    ~Module1();
    string getModuleName();
};