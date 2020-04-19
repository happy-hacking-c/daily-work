
/**
 * 第10堂课作业：5-5
 * 将字符串s中的最多前n个字符与t比较
 * 郑凯
 * 2020年4月20日
 * */
#include <stdio.h>

int mystrncmp(char *s, int n, char *t);

//将字符串s中的最多前n个字符与t比较
int mystrncmp(char *s, int n, char *t)
{
    char *begin = s;

    for(; *s == *t; s++, t++){
        //如果比较n个字符且一直相等
        if((s - begin == n - 1) || *s == '\0') 
           return 0;
    }
       
    return *s - *t;
}


int main()
{
    char s[20] = "zkbhjis";
    char t[10] = "zkbhj";
    int n = 6;

    int comp = mystrncmp(s, n, t);

    if(comp){
        printf("s > t\n");
    }else if(comp == 0){
        printf("s == t\n");
    }else {
        printf("s < t\n");

    }

    return 0;

}

