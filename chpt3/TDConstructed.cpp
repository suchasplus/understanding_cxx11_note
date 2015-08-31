#include <iostream>
#include <list>
#include <vector>
#include <deque>

using namespace std;

class TDConstructed {
    template<class T> TDConstructed(T first, T last) : l(first, last) {}
    list<int> l;

    public:
        TDConstructed(vector<short> & v) : TDConstructed(v.begin(), v.end()) {}
        TDConstructed(deque<int> & d) : TDConstructed(d.begin(), d.end()) {}
        list<int> getData() { return l; }
};

int main(int argc, const char *argv[])
{
    vector<short> v = {1,2,3,4,5};
    TDConstructed tdc(v);
    cout << tdc.getData().size() << endl;
    return 0;
}
