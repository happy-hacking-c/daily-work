//
// Created by junhai on 2020/4/28.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NUMBERIC 1
#define DECR 2
#define FOLD 4
#define DIR 8
#define LINES 100

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;


int charcmp(char s[], char t[]);
void error(char s[]);
int numcmp(char s[], char t[]);
void readargs(int argc, char *argv[]);
int readlines(char *lineptr[], int maxlines);
int mygetline(char [],int);
char *alloc(int n);
void myqsort(void *v[], int left, int right,int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines);
void swap(void *v[],int i, int j);

char option = 0;
int pos1 = 0;// 定位字段开始位置
int pos2 = 0;// 定位字段结束位置


int main(int argc, char *argv[]){
    char *lineptr[LINES];
    int nlines;
    int c;

    readargs(argc, argv);

    if(argc)
        printf("Usage: sort -dfnr \n");
    else{
        if((nlines = readlines(lineptr, LINES)) > 0){
            if(option & NUMBERIC)
                myqsort((void *)lineptr, 0, nlines - 1,
                        (int (*)(void *, void *))numcmp);
            else
                myqsort((void *)lineptr, 0, nlines - 1,
                        (int (*)(void *, void *))charcmp);
            writelines(lineptr, nlines);
        }else{
            printf("input too bit to sort\n");
            return -1;
        }
    }
    return 0;
}

void readargs(int argc, char *argv[]){
    int c;
    while ((--argc > 0 && (c = (*++argv)[0]) == '-') || c == '+') {
        if(c == '-' && !isdigit(*(argv[0] + 1))){
            // 遍历命令列表
            while((c = *++argv[0])){
                switch(c){
                    case 'd':
                        option |= DIR;
                        break;
                    case 'f':
                        option |= FOLD;
                        break;
                    case 'n':// 按数字排序
                        option |= NUMBERIC;
                        break;
                    case 'r':
                        option |= DECR;
                        break;
                    default:
                        printf("sort: illegal option %c\n", c);
                        error("Usage: sort -dfnr [+pos1] [-pos2]");
                        break;
                }
            }
        }else if(c == '-')// 遇到可选的字段排序选项
            pos2 = atoi(argv[0] +  1);
        else if((pos1 = atoi(argv[0] + 1)) < 0)
            error("Usage: sort -dfnr [+pos1] [-pos2]");
    }
}

int readlines(char *lineptr[], int maxlines)
{
    int len,nlines;
    char *p,line[LINES];
    nlines = 0;
    while ((len = mygetline(line,LINES))> 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return  -1;
        else{
            line[len-1] = '\0';
            strcpy(p,line);
            lineptr[nlines++] = p;
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

void writelines(char *lineptr[],int nlines)
{
    int i;
    for (i = 0;i<nlines ;i++)
        printf("%s\n",lineptr[i]);
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

int numcmp(char *s1,char *s2)
{
    double  v1,v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if(v1<v2) {
        return -1;
    } else if (v1 > v2) {
        return  1;

    } else
        return 0;

}

int charcmp(char *s,char *t)
{
    for( ; *s == *t;s++,t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}


void swap(void *v[],int i, int j)
{
    void  *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;

}
void myqsort(void *v[],int left, int right ,int (*comp)(void *,void *))
{
    int i,last;
    void swap(void *v[],int ,int );
    if (left >= right)
        return;
    swap(v,left,(left+right)/2);
    last = left;
    for (int i = left+1; i <= right ; ++i)
    {
        if ((*comp)(v[i],v[left])<0) {
            swap(v,++last,i);
        }
    }
    swap(v,left,last);
    myqsort(v,left,last-1,comp);
    myqsort(v,last +1 ,right,comp);

}
void error(char *s){
    printf("%s",s);
}

