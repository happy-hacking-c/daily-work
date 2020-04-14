#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main() {
    
    int x = 22;
    char s[11]; 
    int w = 4;
    itoa(x,s,w);
    int i = 0;
    while (s[i] != '\0')
    {
        printf("%c\n", s[i++]);

    }
    
    
    return 0;
}

void itoa(int n, char s[], int w){
    int i,sign;
    if((sign = n ) < 0){
        n = -n;
    }
    i = 0;
    do
    {
       s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if(sign < 0 ){
        s[i++] = '-';
    }
    while (i < w)
    {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);

}

void reverse(char s[]){
    int c,i,j;
    for ( i = 0,j=strlen(s) - 1; i < j; i++,j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    
}


