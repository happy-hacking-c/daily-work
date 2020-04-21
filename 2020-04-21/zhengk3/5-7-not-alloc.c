
/**
 * 第12堂课作业：5-5
 * 重写readLines函数，不使用alloc进行空检分配，使用main中定义的数组
 * 郑凯
 * 2020年4月21日
 * */
#include <stdio.h>
#include <string.h>
#include "alloc.c"

#define MAXLINES 50    /* max #lines to be sorted */
#define MAXLEN 100  /* max length of any input line */
char *lineptr[MAXLINES]; /* pointers to text lines */ 
int readlines(char *lineptr[], int nlines, char (*my)[MAXLEN]);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines; /* number of input lines read */
    char my_array[MAXLINES][MAXLEN];
    if ((nlines = readlines(lineptr, MAXLINES, my_array)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int getline(char *, int);
char *alloc(int);
/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char (*my)[MAXLEN])
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;

    while ((len = getline(line, MAXLEN)) > 0){
        //如果超出数量限制
        if (nlines >= maxlines){
             nlines = -1;
             break;
        }else
        {
            //分配空间
            line[len - 1] = '\0'; /* delete newline */
            strcpy(&my[nlines][0], line);
            lineptr[nlines++] = &my[nlines][0];
        }
    }
    
    return nlines;
}
/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

int getline(char s[], int lim)
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

void swap(char *v[], int i, int j);
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
