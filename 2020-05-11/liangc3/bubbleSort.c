//
// Created by cotton on 2020/5/11.
//
#include <stdio.h>

int main() {
    int a[] = {220, 3, 45, 67, 12, 66, 17, 42, 9, 8};
    int len = (sizeof a)/(sizeof a[1]);
    for (int i = len-1; i > 0; i--) {
        for (int j = 0; j< i; j++) {
            if ( a[j] - a[j+1] > 0) {
                a[j] += a[j+1];
                a[j+1] = a[j] - a[j+1];
                a[j] = a[j] - a[j+1];
            }
        }
    }

    for (int i = 0; i < len; i++) {
        printf("%d\n", a[i]);
    }
}
