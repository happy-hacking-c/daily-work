#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

void ungetch(int c)
{
    if (buf >= BUFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] = c;

}



int main() {
    printf("Hello, World!\n");
    return 0;
}

void ungets(char s[]){
    int len = strlen(s);
    while(len > 0)
        ungetch(s[--len]);
}