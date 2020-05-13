//
// Created by cotton on 2020/5/13.
//
#include <stdio.h>
#include <math.h>
int main() {
    int a[] = {220, 3, 45, 67, 12, 66, 17, 42, 9, 8};
    int len = (sizeof a)/(sizeof a[0]);
    int step = sqrt(len)/1;
    for(; step > 0; step >>= 1) {
        for (int i = 0; i < step; i++) {
            for (int j = i+ step; j < len; j += step) {
                for (int k = j; k >= i+step && (a[k] < a[k-step]); k-= step) {
                    a[k] += a[k-step];
                    a[k-step] = a[k] - a[k-step];
                    a[k] = a[k] -  a[k-step];
                }
            }
        }
    }

    for (int i = 0; i < len; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
