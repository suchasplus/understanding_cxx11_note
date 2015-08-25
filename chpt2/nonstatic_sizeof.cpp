#include <iostream>

using namespace std;

struct People {
    public:
        int hand;
        static People * all;
};

int main(int argc, const char *argv[])
{
    People p;
    cout << sizeof ( p.hand  )  << endl;
    cout << sizeof ( People::all  )  << endl; //g++ 98 still work @4.8.3
    cout << sizeof ( People::hand )  << endl; //g++ 98 still work @4.8.3
    return 0;
}
