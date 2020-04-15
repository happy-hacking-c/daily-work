// create by wuym1 hahaha
// 4-7

#include "stdio.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

void ungets(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        ungetch(s[i]);
        i++;
    }
}

int main() {
    char s[100] = "hello world";
    ungets(s);
    printf("%s\n", buf);
    return 0;
}