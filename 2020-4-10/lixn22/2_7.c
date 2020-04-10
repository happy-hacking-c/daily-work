#include <stdio.h>

int invert(unsigned x, int p, int n);
int getbits(unsigned x, int p, int n);
void main() {
    printf("%d\n", ~2);
    printf("%d\n", 0177);

    printf("%d\n", getbits(20, 4, 3));
    printf("%d\n", invert(20, 5, 2));
}

int getbits(unsigned x, int p, int n) {
    return (x >> (p+1 - n)) & ~(~0  << n);
}

int invert(unsigned x, int p, int n) {
    return x ^(~(~0U << n) << p);
}