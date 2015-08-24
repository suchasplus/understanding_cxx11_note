#include <iostream>

using namespace std;


int main(int argc, const char *argv[])
{
#if __cplusplus < 201103L
    cout << "you should use std::tr1::hash_map" << endl;
#else 
    //gcc -std=c++0x __FILE__
    cout << "you can use unordered_map" << endl;
#endif
    return 0;
}
