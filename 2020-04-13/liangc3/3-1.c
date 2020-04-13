//
// Created by cotton on 2020/4/13.
//
#include <stdio.h>

int binsearch(int x, int v[], int n) {
    int low, high, mid;
    high = n - 1;
    low = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x  > v[mid]) {
            low = mid + 1;
        } else {
            high = mid -1;
        }
    }

    if (x == v[low]) {
        return low;
    } else if (x == v[high]) {
        return high;
    } else {
        return -1;
    }
}

int main() {
    int v[8];
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    v[5] = 6;
    v[6] = 7;
    v[7] = 8;
    int x = 6;
    printf("%d\n", binsearch(x, v, 7));
}

