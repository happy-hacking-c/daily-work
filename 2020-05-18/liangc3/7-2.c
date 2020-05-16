//
// Created by cotton on 2020/5/16.
//
#include <stdio.h>
#include <ctype.h>
#define MAXLINE  10
int incPos(int pos, int inc);
int main() {
    int c;
    int pos = 0;
    while( (c = getchar()) != EOF) {
        if (iscntrl(c) || c == ' ') {
            pos = incPos(pos, 4);
            printf("\\x%02x", c);
            if (c == '\n') {
                putchar('\n');
                pos = 0;
            }
        } else {
            pos = incPos(pos, 1);
            putchar(c);
        }
    }
    return 0;
}

int incPos(int pos, int inc) {
    if ((pos += inc) > MAXLINE) {
        pos = inc;
        putchar('\n');
    }
    return pos;
}
