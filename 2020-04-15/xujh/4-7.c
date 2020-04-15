//
// Created by junhai on 2020/4/15.
//

#include <stdio.h>
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

int testUngets() {
    char s[100] = "hello world";
    ungets(s);
    printf("%s\n", buf);
    return 0;
}
