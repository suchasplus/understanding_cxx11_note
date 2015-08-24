#include <iostream>

using namespace std;

struct TestStruct {
    TestStruct () : name(__func__) {}
    const char *name;
    // warning: ‘__func__’ is not defined outside of function scope [enabled by default]
    //void FuncFail ( string func_name = __func__) {};
};

int main(int argc, const char *argv[])
{
    TestStruct ts;
    cout << ts.name << endl;
    return 0;
}
