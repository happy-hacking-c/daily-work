#include "stdio.h"

void strncpy(char *s, char *t, int n) {
    int i = 0;
    while (i < n && (*s++ = *t++)) {
        i++;
    }
}

void strncat(char *s, char *t, int n) {
    char *temp = s + n;
    while (*temp++ = *t++) {
        /* code */
    }
}

char strncmp(char *s, char *t, int n) {
    for(; *s == *t; ++s, ++t){
        if(*s == '\0' || --n <= 0)
            return 0;
    }
    return *s - *t;
}

int main() {
    char *s = "11111";
    char *t = "12345";
    int n = 3;

    strncat(s, t, n);
    printf("%s", s);

    return 0;
}