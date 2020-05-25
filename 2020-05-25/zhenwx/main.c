/*
 * Functions like isupper can be implemented to save space or to save time.
 * Explore both possibilities.
 */

#include <stdio.h>
#include <stdlib.h>

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