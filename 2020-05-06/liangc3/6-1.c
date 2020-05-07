//
// Created by cotton on 2020/5/5.
//

#include <stdio.h>
struct key {
    char *word;
    int count;
} keytab[] = {
        {"auto", 0},
        {"break", 0},
        {"case", 0},
        {"char", 0},
        {"const", 0},
        {"continue", 0},
        {"default", 0},
        {"unsigned", 0},
        {"void", 0},
        {"volatile", 0},
        {"while", 0}
};
#define MAXLEN 100
#define KEYTABLEN (sizeof keytab /sizeof keytab[0])

#include "cgetword.c"
#include "cbinsearch.c"

int main() {
    char *word;
    int n, i = 0;
    while(cgetword(word, MAXLEN) != EOF) {
        if (isalpha(word[0])) {
            if ((n = cbinsearch(word, keytab, KEYTABLEN)) >= 0) {
                keytab[n].count++;
            }
        }
    }

    for (; i < KEYTABLEN; i++) {
        printf("key: %s, count: %d\n", keytab[i].word, keytab[i].count);
    }
    return 0;
}