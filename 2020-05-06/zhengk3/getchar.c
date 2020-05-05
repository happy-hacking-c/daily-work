#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void);
void ungetch(int);

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

//将字符压回到输入（buf）中
void ungetch(int c)
{
    if (bufp >= BUFSIZ){
        printf("ungetch: too many characters\n");
    }else{
        buf[bufp++] = c;
    }
}