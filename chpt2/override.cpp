#include <iostream>
using namespace std;

struct Base {
    virtual void Turing () = 0;
    virtual void Dijkstra() = 0;
    virtual void VNeumann(int g) = 0;
    virtual void DKnuth() const;
    void Print();
};

struct DerivedMid : public Base {
    // void VNeumann(double g);
};

struct DerivedTop : public DerivedMid {
    void Turing()           override ;
    void Dikjstr()          override ; //misspelt
    void VNeumann(double g) override ; //diff param
    void DKnuth()           override ; //non const
    void Print()            override ; //non virtual function
};

int main(int argc, const char *argv[])
{
    
    return 0;
}
