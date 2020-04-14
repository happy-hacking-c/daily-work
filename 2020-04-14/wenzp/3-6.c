#include <stdio.h>
#include <ctype.h>
//整数的各位数字加‘0’转换为char型并保存到字符数组中                                                                                           
int itoa(int n, char s[])
{
    int i;
    int j;
    int sign;

    sign = n;    //记录符号
    if(sign < 0)
    {
       n = -n;  //变为正数处理 
    }

    i = 0;
    do{
        s[i++] = n % 10 + '0';  //取下一个数字
    }while((n /= 10) > 0);

    if(sign < 0 )
    {
        s[i++] = '-';
        s[i] = '\0';
    }

    for(j = i; j >= 0; j-- )
    {
        printf("%c \r\n", s[j]);
    }
    return 0;
}
int main()
{
    int n;
    char s[20];

    n = -688;
    itoa(n, s);
    return 0;
}
