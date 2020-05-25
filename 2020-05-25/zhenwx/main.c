#include <stdio.h>

int myisupper(int);

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') continue;

        if (c >= 'A' && c <= 'Z')
            printf("true\n");
        else
            printf("false\n");
    }

    return 0;
}