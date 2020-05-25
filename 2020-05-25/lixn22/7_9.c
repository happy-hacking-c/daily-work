#include <stdio.h>

#define ISUPPER(c) (c >= 'A' && c <= 'Z' ? 1 : 0) 

int main(void) {
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            continue;

        if (ISUPPER(c) == 1)
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}
