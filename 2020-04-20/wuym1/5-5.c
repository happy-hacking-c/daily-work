#include "stdio.h"

void mystrncpy(char *s, char *t, int n) {
    char *temp = t + n;
    while ((*s++ = *temp++)) ;
}

void mystrncat(char *s, char *t, int n) {
    while (*s != '\0') {
        s++;
    }
    while ((*s++ = *t++) != '\0' && --n >= 0);
    return s;
}

char mystrncmp(char *s, char *t, int n) {
    for(; *s == *t; ++s, ++t) {
        if(*s == '\0' || --n <= 0)
            return 0;
    }
    return *s - *t;
}

int main() {
    char *s = "abcde";
    char *t = "12345";
    int n = 3;

    mystrncat(s, t, n);
    printf("%s", s);

    return 0;
}