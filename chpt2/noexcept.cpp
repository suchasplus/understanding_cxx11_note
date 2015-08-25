#include <iostream>

using namespace std;

void Throw() { throw 1; }
void NoBlockThrow() { Throw(); }
void BlockThrow() noexcept { Throw(); }

int main(int argc, const char *argv[])
{
    try {
        Throw();
    } catch(...) {
        cout << "Found throw..." << endl; 
    }

    try {
        NoBlockThrow();
    } catch(...) {
        cout << "Throw is not blocked..." << endl;
    }

    try {
        BlockThrow();
    } catch(...) {
        cout << "Should Never get this..." << endl;
    }
    return 0;
}
