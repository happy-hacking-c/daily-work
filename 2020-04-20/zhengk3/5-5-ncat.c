
/**
 * 第10堂课作业：5-5
 * 将字符串t中的前n个字符复制到s后面
 * 郑凯
 * 2020年4月19日
 * */
#include <stdio.h>

char *mystrncat(char *s, int n, char *t);

//将字符串t中的前n个字符复制到s后面
char *mystrncat(char *s, int n, char *t)
{
    char *spoint = s;
    int length = 0;
    //将s指针移动到结束符的地方
    while(*s++)
    ;

    //回到\0位置
    s--;

    //注意判断顺序的区别
    while(++length <=n && (*s++ = *t++))
    ;

    //结尾补\0
    *s++ = '\0';
       
    return spoint;
}


int main()
{
    char s[20] = "mywebis";
    char t[10] = "zkbhj";
    char *re;
    int n = 3;

    re = mystrncat(s, n, t);

    printf("cat result:%s\n",re);

    return 0;

}

