//
//  main.c
//  wuym1
//
//  Created by min on 2020/4/9.
//  Copyright © 2020 min. All rights reserved.
//

#include <stdio.h>

int invert(int x, int p, int n) {
    return x ^ (~(~0 << n) << (p - n + 1));
}

int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; b++) {
        x &= x - 1;
    }
    return b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    printf("%d\n", invert(10, 3, 2));
    printf("%d\n", bitcount(34));
    
    return 0;
}
