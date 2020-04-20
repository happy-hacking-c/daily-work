//
// Created by cotton on 2020/4/20.
//
#include <stdio.h>

void astrcpy(char *s, char *t);
void astrncpy(char *s, char *t, int n);
void astrcat(char *s, char *t);
void astrncat(char *s, char *t, int n);
int astrcmp(char *s, char *t);
int astrncmp(char *s, char *t, int n);

int main() {
    char s[5] = "ilove";
    char *t = "ilovey";
//    astrcpy(s, t);
//    astrncpy(s, t, 2);
//    astrcat(s, t);
//    astrncat(s, t, 2);
//    printf("%s\n", s);
//    printf("%d\n", astrcmp(s, t));
    printf("%d\n", astrncmp(s, t, 6));
    return 0;
}

void astrcpy(char *s, char *t) {
    while((*s++ = *t++) != '\0')
        ;
}

void astrncpy(char *s, char *t, int n) {
    while((*s++ = *t++) != '\0' && --n > 0)
        ;
}

void astrcat(char *s, char *t) {
    while(*s++ != '\0')
        ;
    s--;
    while((*s++ = *t++) != '\0')
        ;
}

void astrncat(char *s, char *t, int n) {
    while(*s++ != '\0')
        ;
    s--;
    while((*s++ = *t++) != '\0' && --n > 0)
        ;
}

int astrcmp(char *s, char *t) {
    while(*s == *t && *s != '\0') {
        s++;
        t++;
    }
    return *s - *t;
}

int astrncmp(char *s, char *t, int n) {
    while(*s == *t && *s != '\0' && --n > 0) {
        s++;
        t++;
    }
    return *s - *t;
}


