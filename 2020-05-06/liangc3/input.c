//
// Created by cotton on 2020/5/5.
//

#include<stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int cgetch() {
    return bufp > 0 ? buf[--bufp] : getchar();
}

void cungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("cungetch: buf is full!!!");
    } else {
        buf[bufp++] = c;
    }
}