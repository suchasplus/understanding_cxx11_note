#include <iostream>

using namespace std;

class HasPtrMem {
    public:
        HasPtrMem() : d(new int(0)) {}
        HasPtrMem(HasPtrMem &h):
            d(new int(*h.d)) {} // copy ctor, malloc on heap, init with *h.d
        ~HasPtrMem() { delete d;}
        int * d;
};


int main(int argc, const char *argv[])
{
    HasPtrMem a;
    HasPtrMem b(a);

    cout << *a.d << endl;
    cout << *b.d << endl;
    return 0;
}
