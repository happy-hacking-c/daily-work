//
// Created by cotton on 2020/4/28.
//

void cswap(char *s[], int i, int j) {
    void *tmp;
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}