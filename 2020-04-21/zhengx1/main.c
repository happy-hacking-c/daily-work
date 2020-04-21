#include <stdio.h>
#include <string.h>

#define  MAXLINES 5000
#define  MAXLEN 100
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *lineptr[MAXLINES];
int readlines(char *lineptr[],int nlines);
int readlinesb(char *lineptr[],int nlines);
char *alloc(int n);
void afree(char *p);
int mygetline(char line[],int maxline);
char stringbuff[ALLOCSIZE];


int main() {
    int nlines;
//    nlines = readlines(lineptr,MAXLINES);
    nlines = readlinesb(lineptr,MAXLINES);
    printf("输入的总行数：%d\n",nlines);
    for (int i = 0; i < nlines; ++i) {
        printf("%s\n",lineptr[i]);
    }
    return 0;
}


int readlines(char *lineptr[],int maxlines)
{
    int len,nlines;
    char *p ,line[MAXLEN];
    nlines = 0;
    while ((len = mygetline(line,MAXLEN)) >0) {
        printf("输入的内容：%s,输入的长度：%d\n",line,len);
//        return 0;
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len -1] = '\0';
            strcpy(p,line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;

}


int readlinesb(char *lineptr[],int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    char *p = stringbuff;
    char *linestop = stringbuff + ALLOCSIZE;
    nlines = 0;
    while((len = mygetline(line, MAXLEN)) > 0){
        if(nlines >= maxlines || p + len > linestop)
            return -1;
        else{
            line[len - 1] = '\0'; // 删除换行符
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;

}

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp -n;
    } else {
        return 0;
    }
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int mygetline(char s[],int lim)
{
    int c,i;
    for (i=0;i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}