
/**
 * 第6堂课作业：3-9
 * 郑凯
 * 2020年4月13日
 * */

#include <stdio.h>
#include <string.h>

//生产外部变量
#define MAX_LENGTH 100

char r[MAX_LENGTH];
char p[MAX_LENGTH];

//函数声明
void itoa(int n, char s[], int b);
void reverse(char s[]);

//函数实现
void itoa(int n, char s[], int b)
{

    int i, sign;

    if ((sign = n) < 0)
       n = -n;

    i = 0;

    do{
        s[i++] = n % 10 + '0';
    }while ((n /= 10) > 0);

    if (sign < 0)
       s[i++] = '-';

    //如果数字长度小于最小宽度，则补空格
    while (i <= (b - 1)){
        s[i++] = ' ';
    }
    
    s[i] = '\0';
    reverse(s);

}


//将原字符串顺序颠倒
void reverse(char s[])
{
    int j = strlen(s)-1 ;
    for( int i = 0; i < strlen(s); i++ ) {
         p[j] = s[i];
         j--;
    }

}


int main()
{
    int n = 2345;
    int b = 8;

    itoa(n , r, b);

    //打印
    printf("%s \n",p);

}