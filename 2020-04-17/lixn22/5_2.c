#include <stdio.h>
#include <ctype.h>
#include <math.h>


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

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    printf("%d", c);
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c), c = getch();)
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    
    printf("%d", c);
    return c;
}

int getfloat(float *fp) {
    int c, sign, frac, digits;
    while (isspace(c = getch())) {
    }

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c) && c != '.') {
            if (c == EOF) {
                return EOF;
            } else {
                ungetch(c);
                return 0;
            }
        }
    }
    *fp = 0;
    frac = 0;
    digits = 0;
        
    for (; isdigit(c) || c == '.'; c = getch())
    {
        if (c == '.')
        {
            frac = 1;
        } else {
            if (!frac) {
                *fp = 10* *fp + (c - '0');
            } else {
                *fp = *fp + ((c - '0') / pow(10, frac));
                frac++;
            }
            digits++;
        }
        
    }

    *fp *= sign;

    if (c == EOF) {
        return EOF;
    } else {
        ungetch(c);
        return digits ? c : 0;
    }
}

int main()
{
    int res;
    float array;
    do {
        res = getfloat(&array);
        if (res > 0) {
            printf("%f", array);
        }
    } while (res > 0);
    
    return 0;
}
