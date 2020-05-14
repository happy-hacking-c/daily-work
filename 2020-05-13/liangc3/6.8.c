//
// Created by cotton on 2020/5/13.
//
#include <stdio.h>
int main() {
    union typeu {
        int ival;
        float fval;
        char *sval;
    } u;
    u.sval = "d";
    printf("%s", u.sval);
    return 0;
}