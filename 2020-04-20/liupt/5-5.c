#include <stdio.h>
char* astrcpy(char *s, char *t,int n);
char* astrncat(char *s, char *t, int n);
int astrncmp(char *s, char *t, int n);

int main(){
    char s[200] = "";
    char t[200] = "hello world!";
    int n = 10;
    int ncmp;
    astrcpy(s,t,n);
    printf("strcpy s = %s \n",s);

    astrncat(s,t,n);
    printf("strncat s = %s \n",s);

    ncmp = astrncmp(s,t,n);
    printf("strstrncmpncat ncmp = %d \n",ncmp);

    return 0;
}

char* astrcpy(char *s, char *t,int n){
    while ((*s++ = *t++) && --n >= 0);
    return s;
}


char* astrncat(char *s, char *t, int n){
    while (*s != '\0'){
        s++;
    }
    while ((*s++  = *t++) != '\0' && --n>=0);
    return s;
}


int astrncmp(char *s, char *t, int n){
    for(; *s == *t; ++s, ++t){
        if(*s == '\0' || --n < 0)
            return 0;
    }
    return *s - *t;
}