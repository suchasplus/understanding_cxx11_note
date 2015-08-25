#include <iostream>

using namespace std;

class MathObject {
    public:
        virtual double Arith() = 0;
        virtual void Print () = 0;
};

class Printable : public MathObject
{
public:
    double Arith() = 0;
    void Print () final {
        std::cout << "Output is :" << Arith() << std::endl;
    }

private:
    /* data */  
};

class Add2 : public Printable {
    public:
        Add2(double a, double b) : x(a), y(b){}
        double Arith() { return x+y ;}
        /*   // compile failed by Printable final print
        void Print () {
            std::cout << "Add2 output is :" << Arith() << std::endl;
        }
        */

    private:
        double x, y;
};

class Mul3 : public Printable {
    public :
        Mul3(double a, double b, double c) : x(a), y(b), z(c) {}
        double Arith() { return x * y * z; }
    private :
        double x, y, z;
};


int main(int argc, const char *argv[])
{
     
    return 0;
}
