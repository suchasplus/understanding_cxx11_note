#include <iostream>
/**
 * suchasplus@gmail.com
 */

using namespace std;

struct A {
    A ( int i ) {
        std::cout << "A ctor : int i = " << i << std::endl;
    }
};

struct B : A {
    B (int i ) : A (i) , d(i) {
        std::cout << "B ctor : int i^2 = " << d * d << std::endl;
    }

    int d;
};

int main(int argc, const char *argv[])
{
    A a(10);
    B b(20);
    return 0;
}
