#include <ctype.h>
#include <stdio.h>

#define MAXLINE 10

int myPos(int pos, int n) {
    if ((pos += n) > MAXLINE) {
        putchar('\n');
        return n;
    } else {
        return pos;
    }
}

int main() {
    int c, pos = 0;

    while ((c = getchar()) != EOF) {
        if (iscntrl(c) || c == ' ') {
            pos = myPos(pos, 6);
            printf("\\%03o", c);
            if (c == '\n') {
                putchar('\n');
                pos = 0;
            }
        } else {
            pos = myPos(pos, 1);
            putchar(c);
        }
    }
    return 0;
}
