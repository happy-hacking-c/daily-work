#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    printf("argv[0] = %s\n", argv[0]);

    int c;
    // cc -o tolower 2020-05-15/zhenwx/main.c
    if (strcmp(argv[0], "./tolower") == 0) {
        while ((c = getchar()) != EOF) putchar(tolower(c));

    // cc -o toupper 2020-05-15/zhenwx/main.c
    } else if (strcmp(argv[0], "./toupper") == 0) {
        while ((c = getchar()) != EOF) putchar(toupper(c));

    // cc -o print 2020-05-15/zhenwx/main.c
    } else {
        while ((c = getchar()) != EOF) putchar(c);
    }

    return 0;
}