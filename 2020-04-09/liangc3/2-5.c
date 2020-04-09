//
// Created by cotton on 2020/4/9.
//

#include <stdio.h>
#define LIMIT 500

int any(char s1[], char s2[]);

void getLine(char s[]);

int main() {
    char a[LIMIT],  b[LIMIT];
    getLine(a);
    getLine(b);
    printf("%d\n", any(a, b));
}

void getLine(char s[]) {
    int i, c;
    for (i = 0; i < LIMIT - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    s[i] = '\0';
}


int any(char s1[], char s2[]) {
    int i, j;
    i = 0;

    while (s1[i] != '\0') {
        j = 0;
        while (s2[j] != '\0')
            if (s1[i] == s2[j++])
                return i;
        i++;
    }
    return -1;
}



