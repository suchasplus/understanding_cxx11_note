#include <iostream>

using namespace std;

class HasPtrMem {
    public :
        HasPtrMem() : d(new int(0)) {}
        ~HasPtrMem() { delete d;}

        int * d;
};

int main(int argc, const char *argv[])
{
    HasPtrMem a;
    HasPtrMem b(a);

    cout << *a.d << endl;
    cout << *b.d << endl; //runtime error, multiple delete called in same pos

    return 0;
}
