#include <iostream>
#include <cassert>
#include <cstring>
#include <type_traits>
using namespace std;

char * ArrayAlloc ( int n ) {
    assert( n > 0 );
    return new char[n];
}

enum FeatureSupports {
    C99      = 0x0001,
    ExtInt   = 0x0002,
    SAssert  = 0x0004,
    NoExcept = 0x0008,
    SMAX     = 0x0010,
};

struct Compiler {
    const char * name;
    int spp; // using Festure Supports enum
};

#define assert_static(e) \
    do { \
        enum { assert_static__ = 1/(e) }; \
    } while (0)

template <typename T, typename U> int bit_copy(T& a, U& b) {
    assert_static(sizeof(b) == sizeof(a));
    memcpy(&a, &b, sizeof(b));
};

template <typename T, typename U> int bit_copy11(T& a, U& b) {
    static_assert ( (sizeof(a) == sizeof(b)), "params of bit_copy11 must have same width ");
    memcpy(&a, &b, sizeof(b));
};

int main(int argc, const char *argv[])
{
    char * aalloc = ArrayAlloc(1);
    //char * b = ArrayAlloc(0);

    assert ((SMAX - 1) == (C99 | ExtInt | SAssert | NoExcept ));

    Compiler cpl = { "abc", (C99 | SAssert)};
    if ( cpl.spp & C99) {
        cout << "cpl.spp & C99" << endl;
    }

    int a = 0x2468;
    //double b; //failed
    int b = 0x1234;

    bit_copy( a , b);

    bit_copy11( a , b);

    cout << a << ", "<< b << endl;

    return 0;
}
