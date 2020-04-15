#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) 
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

void ungets(char s[])
{
    size_t len = strlen(s);
    while (len > 0)
    {
        ungetch(s[--len]);
    }
}

int main()
{
    char s[BUFSIZE] = "this is test";
    ungets(s);
    int c;
    while ((c = getch()) != EOF)
    {
        //putchar(c);
        printf("%c", c);
    }
    return 0;
}
