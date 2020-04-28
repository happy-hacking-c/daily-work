//
// Created by cotton on 2020/4/28.
//

#include "csubstr.c"
int cstrcmp(char *s, char *t) {
    int i;
    extern int start, len;
    char ss[len+1], tt[len+1];
    csubstr(s, ss, start, len);
    csubstr(t, tt, start, len);
    for (i = 0; ss[i] == tt[i]; i++) {
        if (ss[i] == '\0')
            return 0;
    }
    return ss[i] - tt[i];
}