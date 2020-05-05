//
// Created by cotton on 2020/4/28.
//

int cstrcmp(char *s, char *t) {
    int i;
    for (i = 0; *s == *t; s++, t++) {
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}