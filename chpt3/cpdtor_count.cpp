#include <iostream>

using namespace std;

class HasPtrMem {
    public :
        HasPtrMem() : d(new int(0)) {
            cout << "Ctor: " << ++ n_ctor << endl; 
        }

        HasPtrMem(const HasPtrMem & h) : d(new int(*h.d)) {
            cout << "Copy Ctor: " << ++ n_cptor << endl;
        }

        ~HasPtrMem() {
            cout << "Dtor : " << ++ n_dtor << endl;
        }

        int * d;
        static int n_ctor;
        static int n_cptor;
        static int n_dtor;

};

int HasPtrMem::n_ctor = 0;
int HasPtrMem::n_cptor = 0;
int HasPtrMem::n_dtor = 0;

HasPtrMem GetTemp() { return HasPtrMem(); }

int main(int argc, const char *argv[])
{
    //g++ -Wall -std=c++0x -fno-elide-constructors cpdtor_count.cpp -o cpdtor_count
    HasPtrMem hpm = GetTemp();
    return 0;
}
