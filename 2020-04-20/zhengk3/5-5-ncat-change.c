
/**
 * 第10堂课作业：5-5
 * 将字符串t中的n个字符复制到s的末尾，不足的地方补*
 * 郑凯
 * 2020年4月19日
 * */
#include <stdio.h>

char *mystrncpy(char *s, int n, char *t);
//void strncat();
//int strncmp(char *s, int n, char *t);

//将字符串t中的前n个字符复制到s后面
char *mystrncpy(char *s, int n, char *t)
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

    printf("frf %d\n",length);

    //如果t中字符少于n个,剩余位置补\0
    //把t中的\0“替换掉”
    s--;
    while(length++ <= n){
        *s++ = '*';
    }
       
    return spoint;
}


int main()
{
    char s[20] = "mywebis";
    char t[10] = "zkbhj";
    char *re;
    int n = 3;

    re = mystrncpy(s, n, t);

    printf("copy result:%s\n",re);

    return 0;

}

