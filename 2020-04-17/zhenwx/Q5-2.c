#include <stdio.h>
#include <ctype.h>

#define BUFFERMAX 100
#define MAXLEN 10

int bufferIndex = 0;
int buffer[BUFFERMAX];

int getch()
{
    return (bufferIndex > 0) ? buffer[--bufferIndex] : getchar();
}

void ungetch(int c)
{
    if (bufferIndex < BUFFERMAX)
        buffer[bufferIndex++] = c;
}

int getfloat(float *pn)
{
    int c, sign;
    while (isspace(c = getch())) /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it is not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    if (c == '.')
    {
        c = getch();
    }

    printf("c = %d\n", c);
    int j = 1;
    for (; isdigit(c); c = getch())
    {
        *pn = *pn * 10 + c - '0';
        j *= 10;
    }

    *pn /= j;
    *pn *= sign;

    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}

int main(int argc, char const *argv[])
{
    /* code */
    float a[3];
    int n;

    for (n = 0; n < MAXLEN && getfloat(&a[n]) != EOF; n++)
        ;

    return 0;
}
