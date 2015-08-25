#include <iostream>

using namespace std;

struct A {
    ~A() { throw 1;}
};
struct B {
    ~B() noexcept(false) { throw 2;} 
};

struct C {
    B b;
};

int funcA() { A a; return 0;}
int funcB() { B b; return 0;}
int funcC() { C c; return 0;}

int main(int argc, const char *argv[])
{
    try {
        funcB();
    } catch(...) {
        cout << "Caught Func B" << endl;
    }

    try {
        funcC();
    } catch(...) {
        cout << "Caught Func C" << endl;
    }

    try {
        funcA(); //Terminate called after throwing an instance of 'int'
    } catch(...) {
        cout << "Should not see this line..." << endl;
    }
    return 0;
}
