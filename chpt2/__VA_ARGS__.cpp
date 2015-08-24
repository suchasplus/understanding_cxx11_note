#include <iostream>
#include <stdio.h>
using namespace std;

#define LOG(...) {\
    fprintf(stderr, "%s: Line %d: \t", __FILE__, __LINE__);\
    fprintf(stderr, __VA_ARGS__);\
    fprintf(stderr, "\n");\
}

int main(int argc, const char *argv[])
{
    int x = 3;
    int y = 6;
    LOG("x = %d, y = %d", x , y)
    return 0;
}
