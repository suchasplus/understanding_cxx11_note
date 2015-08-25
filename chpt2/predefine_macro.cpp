#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    cout << "std clib : " << __STDC_HOSTED__ << endl;
    cout << "std c : " << __STDC__ << endl;
    // __STDC_VERSION__ not impl in gcc or clang
    //cout << "c std version : " << __STDC_VERSION__ << endl;
    cout << "ISO/IEC : " << __STDC_ISO_10646__ << endl;
    return 0;
}
