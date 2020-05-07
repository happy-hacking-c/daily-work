//
// Created by cotton on 2020/5/5.
//
#include "cstrcmp.c"

int cbinsearch(char *word, struct key keytab[], int max) {
    int left = 0, right = max - 1,middle, r;

    while (left <= right) {
        middle = (left + right)/2;
        r = cstrcmp(word, keytab[middle].word);
        if (r == 0) {
            return middle;
        } else if (r < 0) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }

    }
    return -1;
}
