//
//  main.c
//  wuym1
//
//  Created by min on 2020/4/12.
//  Copyright © 2020 min. All rights reserved.
//

#include <stdio.h>

int binsearch(int x, int v[], int n) {
    if (n < 1) {
        return -1;
    }
    
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (v[mid] != x && low <= high) {
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    
    if (v[mid] == x) {
        return mid;
    } else {
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int v[10] = {0, 2, 5, 6, 8, 10, 15, 20, 22, 30};
    printf("%d\n", binsearch(15, v, 10));
    
    return 0;
}
