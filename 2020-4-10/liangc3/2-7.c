//
// Created by cotton on 2020/4/10.
//

#include <stdio.h>

unsigned char getKnife(unsigned char x, int p, int n);
int main() {

    unsigned char x = 244;
    int p = 2;
    int n = 3;

    unsigned char knife = getKnife(x, p, n);

    int reverse = (~x) & knife;

    int unreverse = x & (~knife);

    int r = reverse | unreverse;

    printf("%d\n", r);
}

unsigned char getKnife(unsigned char x, int p, int n) {
    x = 0;
    x = ~x;
    x <<= p;
    x >>= p+n;
    x <<= n;
    return x;
}




