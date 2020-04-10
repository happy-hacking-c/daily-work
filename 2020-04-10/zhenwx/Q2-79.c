#include <stdio.h>

int invert(int x, int p, int n)
{
    return x ^ (~(~0 << n) << (p - n + 1));
}

int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; b++) {
        x &= x - 1;
    }
    return b;
}

int main()
{
    int x, p, n;
    x = 18;
    p = 2;
    n = 6;
    
    printf("invert(%d, %d, %d) = %d\n", x, p, n, invert(x, p, n));
    printf("bitcount(%d) = %d\n", x, bitcount(x));
    return 0;
}