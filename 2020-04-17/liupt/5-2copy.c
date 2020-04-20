#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
int point_found = 0;
int precision = 0;

int getch(void);
void ungetch(int);
int getfloat(int *pn);



int main(){
    int n, array[100], getint(int *);
    for (n = 0; n < 100 && getfloat(&array[n]) != EOF; n++){
        printf("%d \n",array[n]);

    }
    

    return 0;
}

//读取一个字符
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

//压回一个字符
void ungetch(int c)
{
    if(bufp > BUFSIZE) {
        printf("ungetch：too many characters\n");
    }else{
        buf[bufp++] = c;
    }

}

int getfloat(int *pn){
    int c, sign;

    while (isspace(c = getch())) /* skip white space */ 
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') { 
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1; 
    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
    }
    if (c == '.'){
        c = getch();
    }
    
    
    *pn *= sign;
    if (c != EOF) 
        ungetch(c);
    return c;
}