//
// Created by cotton on 2020/4/10.
//

#include <stdio.h>

int bitcount(unsigned x);

int main() {
    unsigned x = 254;
    printf("%d\n", bitcount(x));
}

int bitcount(unsigned x) {
    int count;
    for (count = 0; x > 0; x >>=1)
        if ((x & 01) == 1)
            count++;
    return count;
}



