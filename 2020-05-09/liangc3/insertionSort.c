//
// Created by cotton on 2020/5/9.
//
#include <stdio.h>
int main() {
    int a[] = {220, 3, 45, 67, 12, 66, 17, 42, 9, 8};
    int len = (sizeof a) / (sizeof a[0]);
    for (int i =1; i <= len; i++) {
        for(int j = i; j>=1 && a[j] < a[j-1]; j--) {
            a[j] = a[j] + a[j-1];
            a[j-1] = a[j] - a[j-1];
            a[j] = a[j] - a[j-1];
        }
    }

    for (int i = 0; i < len; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}
