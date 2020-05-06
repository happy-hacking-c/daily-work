
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

//将字符压回到输入（buf）中
void ungetch(int c) {
    if (bufp >= BUFSIZ) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

#define MAXWORD 100

struct key {
    char *word;
    int count;
};

struct key keytab[] = {
    {"auto", 0},     {"break", 0},    {"case", 0},     {"char", 0},
    {"const", 0},    {"continue", 0}, {"default", 0},  {"define", 0},
    {"double", 0},   {"float", 0},    {"include", 0},  {"int", 0},
    {"strct", 0},    {"string", 0},   {"unsigned", 0}, {"void", 0},
    {"volatile", 0}, {"while", 0},

};

#define NKEYS (sizeof keytab / sizeof keytab[0])
struct key keytab[NKEYS];

/* binsearch: find word in tab[0]...tab[n-1] */

int binsearch(char *word, struct key tab[], int n) {
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

/* getword:  get next word or character from input */
int mygetword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    char t;
    while (isspace(c = getch()))
        ;
    if (c != EOF) *w++ = c;
    if (!isalpha(c)) {
        // "XXXX"
        if (c == '\"' || c == '\'') {
            while ((c = getch()) != EOF)
            {
                if (c == '\"' || c == '\'') break;
                *w++ = c;
            }
        }

        // #XXXX _XXXX //XXXX
        else if (c == '#' || c == '_' || (c == '/' && (c = getch()) == '/')) {
            while ((c = getch()) != EOF)
            {
                if (c == '\n') break;
                *w++ = c;
            }
        }

        if (c != '\"' && c != '\n') ungetch(c);

        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

/* count C keywords */
int main() {
    int n;
    char word[MAXWORD];
    while (mygetword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0) keytab[n].count++;

    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;
}
