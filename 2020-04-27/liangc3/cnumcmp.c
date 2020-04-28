//
// Created by cotton on 2020/4/28.
//
#include <stdlib.h>
int cnumcmp(char *s, char *t) {
    double vs, vt;
    extern int start, len;
    char ss[len+1], tt[len+1];
    csubstr(s, ss, start, len);
    csubstr(t, tt, start, len);
    vs = atof(ss);
    vt = atof(tt);
    if (vs < vt) {
        return -1;
    } else if (vs > vt) {
        return 1;
    } else {
        return -1;
    }
}
