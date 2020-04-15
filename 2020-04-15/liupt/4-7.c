#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0 ;

void ungets( char s[]);

void ungetch(int c);

int getch(void);

int main(){
    char s[BUFSIZE] = "223132132131sfsdfs";

    ungets(s);
    

    printf("%s \n",s);
    return 0;
}

void ungetch(int c){
    if(bufp >= BUFSIZE){
        printf("too many chars\n");
    }else{
        buf[bufp++] = c;
    }
    
}

void ungets(char s[]){
    int i = 0;
    while (s[i] != '\0')
    {
        ungetch(s[i++]);
    }

}

int getch(void){
    return (bufp > 0 )?buf[--bufp]:getchar();
}
