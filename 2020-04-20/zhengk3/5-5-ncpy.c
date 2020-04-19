
/**
 * 第10堂课作业：5-5
 * 将字符串t中的前n个字符复制到s中
 * 郑凯
 * 2020年4月20日
 * */
#include <stdio.h>

char *mystrncpy(char *s, int n, char *t);

//将字符串t中的前n个字符复制到s后面
char *mystrncpy(char *s, int n, char *t)
{
    char *spoint = s;
    int length = 0;

    //注意判断顺序的区别
    while(length++ <=n && (*s++ = *t++))
    ;

    //printf("length %d\n",length);

    //如果t中字符少于n个,剩余位置补\0
    //把t中的\0“替换掉”
    s--;
    while(length++ <= n){
        *s++ = '*';
    }

    *s++ = '\0';
       
    return spoint;
}


int main()
{
    char s[20] = "mywebis";
    char t[10] = "zkbhj";
    char *re;
    int n = 7;

    re = mystrncpy(s, n, t);

    printf("copy result:%s\n",re);

    return 0;

}

