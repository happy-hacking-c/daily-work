
/**
 * 第30堂课作业：习题7-2
 * 郑凯
 * 2020年5月18日
 * */
#include<stdio.h>
#include<ctype.h>

#define MAXLINE 100 /* maximum number of chars in one line */
#define OCTLEN  8   /* length of an octal value */

/* print arbitrary input in a sensible way */

int main(void)
{
    int c,pos;
    int inc(int pos,int n);

    pos = 0;        /* position in the line */

    while((c=getchar()) != EOF)
        if(iscntrl(c) || c == ' ')
        {
            /* non-graphic or blank character */
            //非图形字符（控制字符）或者空格
            pos = inc(pos,OCTLEN);
            //打印无符号8进制，3代表最小宽度,0代表前面用0填充，默认用空格
            printf("\\%03o",c);
            /* newline character */
            if(c == '\n')
                pos = 0;
            putchar('\n');
        }
        else
        {
            /* graphic character */
            pos = inc(pos,1);
            putchar(c);
        }
    return 0;
}

/* inc : increment position counter for output */
int inc(int pos,int n)
{
    if(pos + n < MAXLINE)
        return pos + n;
    else
    {
        putchar('\n');
        return n;
    }
}