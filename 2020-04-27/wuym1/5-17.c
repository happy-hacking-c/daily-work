#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 5000
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void mqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int agetline(char *s, int lim);
int mystrcmp(char *s, char *t);
char *alloc(int);
int begin, len = 0;

int main(int argc, char *argv[]) {
    int from = 0;
    int c, nlines;
    int numeric = 0;
    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = (*++argv[0]))) {
            switch (c) {
                case 'n':
                    numeric = 1;
                    argc--;
                    printf("number \n");
                    break;
                case 'b':
                    begin = atoi(*++argv);
                    argc--;
                    printf("begin %d\n", begin);
                    break;
                case 'l':
                    len = atoi(*++argv);
                    argc--;
                    printf("len %d\n", len);
                    break;
                default:
                    argc = 0;
                    break;
            }
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        mqsort((void **)lineptr, 0, nlines - 1,
               (int (*)(void *, void *))(numeric ? numcmp : mystrcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

void mqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void mswap(void *v[], int, int);
    if (left >= right) return;
    mswap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0) mswap(v, ++last, i);
    mswap(v, left, last);
    mqsort(v, left, last - 1, comp);
    mqsort(v, last + 1, right, comp);
}

void mswap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void writelines(char *lineptr[], int nlines) {
    int i = 0;
    while (nlines-- > 0) printf("#%d %s\n", i++, *lineptr++);
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = agetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

int agetline(char *s, int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int numcmp(char *s1, char *s2) {
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int mystrcmp(char *s, char *t) {
    if (begin != 0) {
        while (begin-- > 0) {
            if (*s != '\0') s++;
            if (*t != '\0') t++;
        }
    }
    if (len > 0) {
        len = -1;
    }
    for (; *s == *t; s++, t++)
        if (*s == '\0') return 0;
    if (len > 0) {
        len--;
    }
    if (len == 0) {
        return 0;
    }
    return *s - *t;
}