
/**
 * 第9堂课作业：5-2
 * 郑凯
 * 2020年4月17日
 * */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
int point_found = 0;
int precision = 0;

float getfloat(float *pn);
void ungetch(int);
int getch(void);


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

float getfloat(float *pn)
{

    int c, sign,i;

    while(isspace(c = getch()))
    ;

    if(!isdigit(c) && c != EOF && c!='+' && c!='-' && c!='.') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if(c == '.') {
        point_found = 1;
    }

    if (c == '+' || c == '-' || c == '.')  {
        c = getch();
    }

    if(point_found) {

        for(; isdigit(c); c = getch()){
            ++precision;
             printf("right char is:%c\n", c);
            *pn += (double)(c - '0')/pow(10, precision);
        }
         
    }else{
        for( *pn = 0; isdigit(c); c = getch()){
            printf("left char is:%c\n", c);
             *pn = 10 * *pn + (c - '0');
        }
        
    }

    
    *pn *= sign;

    if(c != EOF){
        ungetch(c);
    }


    return c;

}

int main()
{

    float x;
    char numbers[BUFSIZE];

    for(int i = 0; i < BUFSIZE && getfloat(&x) != EOF; i++) 
    ;

    printf("the first float is : %f\n", x);

    return 0;
}


