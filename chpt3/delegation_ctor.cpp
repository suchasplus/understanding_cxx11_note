#include <iostream>

using namespace std;

class Info1 {
    public:
        Info1() { InitRest(); }
        Info1(int i) : Info1() { type = i; }
        Info1(char e) : Info1() { name = e;}

    private:
        void InitRest() {}
        int type {1};
        char name {'a'};
};

// failed
/*
struct Rule1 {
    int i ;
    Rule1(int a) : i(a) {}
    Rule1(): Rule1(40), i(1) {} // won't compile : mem-initializer for 'Rule1::i' follows constructor delegation
};
 */

class Info2 {
    public:
        Info2() : Info2(1, 'a') {}
        Info2(int i) : Info2(i,'a') {}
        Info2(char e) : Info2(1, e) {}

    private:
        Info2(int i, char e ): type(i), name(e) { type = i; name = e;}
        int type;
        char name;
};

//chain of delegation
class Info3 {
    public:
        Info3() : Info3(1) {}
        Info3(int i) : Info3(i, 'a') {}
        Info3(char e) : Info3(1, e) {}

    private:
        Info3(int i, char e) : type(i), name (e) {}
        int type;
        char name;
};

int main(int argc, const char *argv[])
{
    Info1 i1(10);
    Info2 i2();
    return 0;
}
