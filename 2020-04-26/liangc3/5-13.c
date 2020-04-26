//
// Created by cotton on 2020/4/26.
// eg:   ./a.out -20
//

#include <stdio.h>
#define MAXLINES 10000
#define MAXINPUT 1000000
char *lineptr[MAXLINES];

int readline(char *s[], int maxlines, char input[]);
void wirteline(char *s[], int maxlines);
void wirtelastline(char *s[], int maxlines, int last);

int main(int argc, char *argv[]) {
    char c;
    int row = 0;
    while(--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0]) != '\0' && c >= '0' && c <= '9') {
            row = row * 10 + c - '0';
        }
    }
    if (row == 0) {
        row = 10;
    }

    int maxLine;
    char input[MAXINPUT];
    if ((maxLine = readline(lineptr, MAXLINES, input)) >= 0)
        wirtelastline(lineptr, maxLine, row);
    return 0;
}

int readline(char *s[], int maxlines, char input[]) {
#define MAXLINE 1000
    char line[MAXLINE];
    int len, i;
    char *p;
    int agetline(char s[], int maxline);
    char *alloc(char input[], char* inputp, int n);
    void astrcpy(char *s, char *t);
    i = 0;
    char *inputp = input;
    while((len = agetline(line, MAXLINE)) > 0) {
        if (i >= maxlines || (p = alloc(input, inputp, len)) == 0) {
            return -1;
        }
        line[len - 1] = '\0';
        astrcpy(p,line);
        s[i++] = p;
        inputp += len;
    }
    return i;
}

void wirteline(char *s[], int maxlines) {
    while(maxlines-- > 0) {
        printf("%s\n", *s++);
    }
}

void wirtelastline(char *s[], int maxlines, int last) {
    while(maxlines-- > 0) {
        if (maxlines < last) {
            printf("%s\n", *s++);
        }
    }
}


int agetline(char s[], int maxline) {
    int i = 0;
    char c;
    while(i < maxline - 1 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

void astrcpy(char *s, char *t) {
    while((*s++ = *t++) != '\0')
        ;
}

char *alloc(char input[], char* inputp, int n) {
    if (input + MAXINPUT - inputp > n) {
        inputp += n;
        return inputp - n;
    }
    return 0;
}





