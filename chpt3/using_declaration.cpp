#include <iostream>
using namespace std;

struct Base {
    void f(double i) {
        std::cout << "Base : double " << i << std::endl;
    }

    void f(int i) {
        std::cout << "Base : int " << i << " with " << __func__ << " "<< __PRETTY_FUNCTION__<< std::endl;
    }
};

struct Derived : Base {
    using Base::f;
    void f(string i) {
        std::cout << "Derived : String " << i << std::endl;
    }
};

struct A {
    A(int i) {}
    A(double d, int i) {}
    A(float f, int i, const char* c) {} 
};

struct B : A {
    using A::A;
    virtual void ExtraInterface();
};

int main(int argc, const char *argv[])
{
    Base base;
    base.f(4.5);
    base.f(4);

    std::string str("test string");
    Derived drd;
    drd.f(8);
    drd.f(str);
    return 0;
}
