
/**
 * 第18堂课作业：5-17
 * 输出输入的最后n行内容
 * 郑凯
 * 2020年4月27日
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alloc.c"
#define MAXLINES 5000    /* max #lines to be sorted */
#define MAXLEN 1000
char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void _qsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *));
int numcmp(char *, char *);
//int strcmp(char *s, char *t);
int _getline(char *, int);
char *alloc(int);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;      /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        _qsort((void **)lineptr, 0, nlines - 1,
              (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}
/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    //如果没有任何输入
    if(!nlines)
       printf("no input\n");
    else{
        for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
    }
    
}

/* _qsort: sort v[left]...v[right] into increasing order */
void _qsort(void *v[], int left, int right,
           int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    _qsort(v, left, last - 1, comp);
    _qsort(v, last + 1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
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

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
// int strcmp(char *s, char *t)
// {
//     for (; *s == *t; s++, t++)
//         if (*s == '\0')
//             return 0;
//     return *s - *t;
// }

void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int _getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
