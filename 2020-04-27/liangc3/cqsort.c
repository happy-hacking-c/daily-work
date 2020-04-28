//
// Created by cotton on 2020/4/28.
//
#include "cswap.c"
#include "cstrcmp.c"
#include "cnumcmp.c"
#include <stdio.h>
void cqsort(void *s[], int left, int right, int(*cmp)(void *, void *)) {
    if (left >= right)
        return;
    int last, i;
    last = left;
    cswap(s, left, (left + right)/2);
    for (i = left + 1; i <= right; i++) {
        if ((*cmp)(s[i], s[left]) < 0) {
            cswap(s, ++last, i);
        }
    }
    cswap(s, left, last);
    cqsort(s, left, last -1, cmp);
    cqsort(s,last + 1, right, cmp);
}

