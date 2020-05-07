//
// Created by cotton on 2020/5/7.
//

#include <stdio.h>

int main () {
    int a[10] = {10, 3, 23, 45, 4, 1, 9, 20, 33, 15};

    int i, j, c, tmp,len = sizeof a/ sizeof a[0];

    for (i = 0; i < len; i++) {
        c = i;
        for (j = i + 1; j < len; j++) {
            if (*(a+c) > *(a+j)) {
                c = j;
            }
        }
        if (c > i) {
            tmp = *(a+i);
            *(a+i) = *(a+c);
            *(a+c) = tmp;
        }
    }

    for (i = 0; i < len; i++) {
        printf("%d\n", *(a+i));
    }
}