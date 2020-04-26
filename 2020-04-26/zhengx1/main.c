#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEFLINES  10
#define LINES 100//最大输入行数
#define MAXLEN 100

void error(char *p);
int mygetline(char *line, int n);

int main(int argc, char *argv[]){
    char *p, *buf, *bufend;
    char line[MAXLEN];//  当前输入行
    char *lineptr[LINES]; // 记录每行输入
    int first, i, last, len, n, nlens;

    if(argc == 1)
        n = DEFLINES;// 默认n
    else if(argc == 2 && (*++argv)[0] == '-')
        n = atoi(argv[0] + 1);// 因为判断条件中，argv已自增，所以这里为argv[0]
    else// 如果参数不是两个，或者第二个参数不以'-'开头，则报错
        error("usage: tail [-n]");
    // 不合法n的处理
    if(n < 1 || n > LINES)
        n = LINES;
    printf("打印行数%d",n);
    // 初始化指针数组
    for(i = 0; i < LINES; ++i)
        lineptr[i] = NULL;
    if((p = buf = malloc(LINES * MAXLEN)) == NULL)
        error("tail: can't allocate buf");
    bufend = buf + LINES * MAXLEN;
    last = 0;
    int nlines = 0;
    while((len = mygetline(line, MAXLEN) > 0)){
        // 如果缓冲区空间不够，则重置p为缓冲区开头
        if(p + len + 1 >= bufend)
            p = buf;
        lineptr[last] = p;
        strcpy(lineptr[last], line);
        // 如果last达到了LINES，则重置last
        if(++last >= LINES)
            last = 0;
        p += len + 1;
        nlines++;// 总行数递增
    }
    printf("共输入的%d行",nlines);
    if(n > nlines)
        n = nlines;
    first = last - n;
    if(first < 0)
        first += LINES;
    // 取模运算使得i保持在0到LINES-1之间
    for(i = first; n-- > 0; i = (i + 1) & LINES)
        printf("%s", lineptr[i]);
    return 0;
}

void error(char *s){
    printf("%s\n", s);
    exit(1);
}

int mygetline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        ++i;
    }
    s[i] = '\0';
    return i;
}