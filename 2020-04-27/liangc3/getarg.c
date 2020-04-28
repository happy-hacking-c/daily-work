//
// Created by cotton on 2020/4/27.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int start = 0;
int len = 0;
int numeric = 0;

void getarg(int argc, char *argv[]) {
    while(--argc > 0) {
        ++argv;
        if (strcmp(*argv, "-n") == 0) {
            numeric = 1;

        } else {

            if (start > 0) {
                len = atoi(*argv);
            } else {
                start = atoi(*argv);
            }
        }
    }

    printf("numeric = %d\n", numeric);
    printf("start = %d\n", start);
    printf("len = %d\n", len);
}