#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE 50

int getch(void);
void ungetch(int);
char buf[BUFSIZE];
int bufp = 0;
int getfloat(float *);

int main() {
    float array[SIZE];
    int n;
    for (n = 0;n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;
    for (;n>=0;n--)
        printf("%f\n",array[n]);
    return 0;
}

int getfloat(float *pn){

    int c, sign;
    float power;
    // 跳过前导空格
    while(isspace(c = getch()))
        ;
    printf("%d\n",c);
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    // 整数部分
    for(*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + c - '0';
    printf("a %f\n", *pn);
    if(c == '.')
        c = getch();
     printf("b %f\n", *pn);
    for(power = 1.0; isdigit(c); c = getch()){
        *pn = 10.0 * *pn + c - '0';
        power *= 10.0;
    }
    *pn *= sign / power;
    if(c != EOF)
        ungetch(c);
    return c;
}


int getch() {
    return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch:too many characters\n");
    else
        buf[bufp ++] = c;
}