#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float *pn);



int main(){
    float pn = 0.0;
    getfloat(&pn);

    

    printf("%f \n",pn);
    return 0;
}

int getfloat(float *pn){
    int c, sign;
    float power;

    while (isspace(c = getch())) /* skip white space */ 
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') { 
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1; 
    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0.0; isdigit(c); c = getch()){
        *pn = 10.0 * *pn + (c - '0');
    }
    if (c == '.'){
        c = getch();
    }
    for (power = 0.0; isdigit(c); c = getch())
    {
         *pn = 10.0 * *pn + (c - '0');
         power *= 10;
    }
    
    *pn *= sign/power;
    if (c != EOF) 
        ungetch(c);
    return c;
}