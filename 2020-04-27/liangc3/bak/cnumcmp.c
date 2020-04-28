//
// Created by cotton on 2020/4/28.
//
#include <stdlib.h>
int cnumcmp(char *s, char *t) {
    double vs, vt;
    vs = atof(s);
    vt = atof(t);
    if (vs < vt) {
        return -1;
    } else if (vs > vt) {
        return 1;
    } else {
        return -1;
    }
}
