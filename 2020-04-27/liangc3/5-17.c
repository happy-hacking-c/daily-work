//
// Created by cotton on 2020/4/27.
//
#include <stdio.h>
//#include "csubstr.c"
#include "getarg.c"
#include "input.c"
#include "cqsort.c"

#define AMAXINPUT 1000000
#define AMAXLINES 1000
int start, end;
//void csubstr(char *raws, char *s, int begin, int len);

int main(int argc, char *argv[]) {
    char *lineptr[AMAXLINES];
    int row;
    getarg(argc, argv);
    extern int numeric;
    row = readline(lineptr, AMAXLINES);
    cqsort((void **)lineptr, 0, row - 1, (int (*)(void *, void *))(numeric ? cnumcmp : cstrcmp));
    wirteline(lineptr, row);
}


