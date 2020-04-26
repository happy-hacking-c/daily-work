#include <stdio.h>

#define MAXLINE 100

int getline0(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main(int argc, char const *argv[]) {
    int n = 10;

    if (argc >= 2) {
        sscanf(argv[1], "%d", &n);
    }

    if (n < 1) {
        n = 10;
    }

    printf("n = %d\n", n);

    char line[MAXLINE];
    int i = 1;
    while (getline0(line, MAXLINE) > 0) {
        if (i >= n) {
            printf("line%d\t%s\n", i, line);
        }
        i++;
    }

    return 0;
}
