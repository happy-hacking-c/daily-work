#include <ctype.h>
#include <stdio.h>

#define MAXLINE 10

int myPos(int pos, int c) {
    int n = (iscntrl(c) || c == ' ') ? 6 : 1;
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
        pos = myPos(pos, c);
        if (iscntrl(c) || c == ' ') {
            printf("\\%03o", c);
            if (c == '\n') {
                putchar('\n');
                pos = 0;
            }
        } else {
            putchar(c);
        }
    }
    return 0;
}
