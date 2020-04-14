//
// Created by cotton on 2020/4/14.
//

#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int i, j, len = strlen(s);
    char tmp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

void itoa(int n, char s[], long l){
    int sign, i;
    if ((sign = n) < 0) {
        n = -n;

    }

    for(i = 0;n != 0; n /= 10) {
        s[i++] = n % 10 + '0';
    }

    if (sign < 0) {
        s[i++] = '-';
    }

    while (i < l) {
        s[i++] = 32;
    }

    reverse(s);
    s[i] = '\0';
}

int main() {
    int n = -256;
    char s[100];
    itoa(n, s, 10);
    printf("%s\n", s);
    return 0;
}

