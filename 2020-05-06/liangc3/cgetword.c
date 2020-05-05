//
// Created by cotton on 2020/5/5.
//
#include <ctype.h>
#include "input.c"

int cgetword(char *word, int maxLen) {
    int c;
    char *w = word;

    while (isspace(c = cgetch()))
        ;

    if (c == '#') {
        while((c = cgetch()) != '\n')
            ;
    }

    if (c == '/') {
        if ((c = cgetch()) == '/') {
            while((c = cgetch()) != '\n')
                ;
        } else {
            cungetch(c);
        }
    }

    if (isalpha(c)) {
        *word++ = c;
    } else {
        *word++ = '\0';
        return c;
    }

    for (; maxLen-- > 0; word++) {
        if (!isalnum(*word = cgetch()) && *word != '_') {
            cungetch(*word);
            break;
        }
    }
    *word = '\0';
    return *w;
}