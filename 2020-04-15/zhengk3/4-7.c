
/**
 * 第7堂课作业：4-7
 * 郑凯
 * 2020年4月15日
 * */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int c);
void ungets(char s[]);

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

//将字符压回到输入（buf）中
void ungetch(int c)
{
    if (bufp >= BUFSIZ){
        printf("ungetch: too many characters\n");
    }else{
        buf[bufp++] = c;
    }
}

//将字符串压回到输入（buf）中
void ungets(char s[])
{
    int len = strlen(s);

    for(int i = --len; i >= 0; i--) {
        ungetch(s[i]);
    }

}

int main()
{

    //将字符串压入输入中(思考：下面两种初始化方式差异是啥？)
    //int s[]= {'a','b','e','f','p'};
    char s[] = "abefp";
  
    ungets(s);

    //输出输入中的内容
    printf("buf's content is: %s", buf);
    

    return 0;
}


