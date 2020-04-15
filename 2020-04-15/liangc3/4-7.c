//
// Created by cotton on 2020/4/15.
//

#include <stdio.h>


void ungetch(int c);

void ungets(char s[]);
#define BUFSIZE  100
char buf[BUFSIZE];
int bufp = 0;

int main() {
    char input[] = "love";
    ungets(input);
    printf("%s\n",buf);
}

void ungetch(int c) {
    if (bufp < BUFSIZE) {
        buf[bufp++] = c;
    } else {
        printf("ungetch: has too many char");
    }
}

void ungets(char s[]) {
    int i=0;
    while(s[i] != EOF && s[i] != '\0') {
        ungetch(s[i++]);
    }
    ungetch('\0');
}