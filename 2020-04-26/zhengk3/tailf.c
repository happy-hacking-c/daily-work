
/**
 * 第17堂课作业：5-13
 * 输出输入的最后n行内容
 * 郑凯
 * 2020年4月25日
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alloc.c"

#define MAXLINES 5000    /* max #lines to be saved */
char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int printLines);

/* tailf input last n lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int printLines;

    //读取输入参数n的值
    if(argc <2 || (printLines = atoi(*++argv)) <= 0)
        printLines = 10;
    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        writelines(lineptr, nlines, printLines);
        return 0;
    }
    else
    {
        printf("error: input too big to tailf\n");
        return 1;
    }
}
#define MAXLEN 1000 /* max length of any input line */
int _getline(char *, int);
char *alloc(int);
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
void writelines(char *lineptr[], int nlines, int printLines)
{
    int i;
    //如果没有任何输入
    if(!nlines)
       printf("no input\n");
    else if(nlines <= printLines) {
        //如果输入行数小于打印的行数n，则全部打印
        printf("the last %d lines are:\n", printLines);
        for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
    }else{
        printf("the last %d lines are:\n", printLines);
        //计算起始位置
        i = nlines - printLines;
        for (; i < nlines; i++)
        printf("%s\n", lineptr[i]);
    }
    
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

