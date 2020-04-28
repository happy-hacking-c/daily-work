//
// Created by cotton on 2020/4/27.
//

void csubstr(char *raws, char *s,int begin, int len) {
    int i = 0;
    while (*raws != '\0' && i++ < begin)
        raws++;
    i = 0;
    while (*raws != '\0' && i < len) {
        s[i++] = *raws;
        raws++;
    }
    s[++i] = '\0';
}