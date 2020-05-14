#include <stdio.h>

int main()
{
    struct Bit
    {
        unsigned a : 1;
        unsigned b : 2;
        unsigned c : 3;
        unsigned d : 4;
    } B;

    B.a = 1;
    B.b = 3;
    B.c = 7;
    B.d = 15;
    printf("%d, %d, %d, %d\n", B.a, B.b, B.c, B.d);

    return 0;
}