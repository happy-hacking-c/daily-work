#include <stdio.h>
#include <string.h>

#define MAXLINES 5000    /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

#define MAXLEN 1000 /* max length of any input line */

char buff[10000];

void qsort(char *lineptr[], int left, int right);

/* getline: read a line into s, return length */
int getline1(char s[], int lim) {
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

int readlines(char *lineptr[], int maxlines, char (*my)[MAXLEN]) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;

    while ((len = getline1(line, MAXLEN)) > 0) {
        //如果超出数量限制
        if (nlines >= maxlines) {
            nlines = -1;
            break;
        } else {
            //分配空间
            line[len - 1] = '\0'; /* delete newline */
            strcpy(&my[nlines][0], line);
            lineptr[nlines++] = &my[nlines][0];
        }
    }

    return nlines;
}

/* readlines: read input lines */
// int readlines0(char *lineptr[], int maxlines) {
//     int len, nlines;
//     char *p, line[MAXLEN];
//     nlines = 0;
//     while ((len = getline1(line, MAXLEN)) > 0)
//         if (nlines >= maxlines || (p = alloc(len)) == NULL)
//             return -1;
//         else {
//             line[len - 1] = '\0'; /* delete newline */
//             strcpy(p, line);
//             lineptr[nlines++] = p;
//         }
//     return nlines;
// }

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++) printf("%s\n", lineptr[i]);
}

/* sort input lines */
int main() {
    int nlines; /* number of input lines read */
    char tmp[MAXLINES][MAXLEN];
    if ((nlines = readlines(lineptr, MAXLINES, tmp)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}