#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        ungetch(s[i]);
        i++;
    }
}

// 返回一个静态局部变量
char * ungets2(char *s)
{
    static char c[BUFSIZE];
    int i = 0;
    while (s[i] != '\0')
    {
        c[i] = s[i];
        i++;
    }
    return c;
}

int main()
{
    char *s = "hello, world.";
    ungets(s);
    printf("buf = %s; ungets2(s) = %s\n", buf, ungets2(s));
    return 0;
}