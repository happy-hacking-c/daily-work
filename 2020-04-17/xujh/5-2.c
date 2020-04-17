//
// Created by cotton on 2020/4/16.
//

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);
int getint(int *p);
int getfloat(float *p);

int main() {
    float a[3];
    int i;

    for (i = 0; getfloat(&a[i]) != EOF; i++)
        ;

    for (i = 0; i < 10; i++) {
        printf("%f\n", a[i]);
    }
}

char buf[100];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= 100) {
        printf("ungetch: too many char");
    } else {
        buf[bufp++] = c;
    }
}

int getint(int *pn) {
    int c;
    int sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+') {
        c = getch();
    }

    for(*pn = 0; isdigit(c); c = getch()) {
        *pn = *pn * 10 + c - '0';
    }
    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }
    return c;
}


int getfloat(float *pn) {
    int c;
    int sign;
    int j;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+') {
        c = getch();
    }

    for(*pn = 0; isdigit(c); c = getch()) {
        *pn = *pn * 10 + c - '0';
    }

    if (c == '.') {
        c = getch();
    }

    for(j = 1; isdigit(c); c = getch()) {
        *pn = *pn * 10 + c - '0';
        j *= 10;
    }

    *pn /= j;
    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}
