#include <stdio.h>
//
char *mystrncpy(char *s,char *ct,int n);
char *mystrncat(char *s,char *ct,int n);
char *mystrnmp(char *s,char *ct,int n);


int main() {
    char s[100] = "";
    char b[100] = "good1";

//    mystrncat(s,b,5);
    mystrncpy(s,b,4);
    printf("%s",s);
    return 0;
}


char *mystrncpy(char *s, char *t, int n){
    while ((*s++ = *t++)  && --n >0 )
        ;
    while (n>0){
        *s ++ = '\0';
        n--;
    }
    return *s;

}


char *mystrncat(char *s, char *t, int n){
    while (*t != '\0'){
        t++;
    }
    while ((*t++  = *s++) != '\0' && n>0){
        n--;
    }
    return t;
}


char *mystrncmp(char *s, char *t, int n){
    for(; *s == *t; ++s, ++t){
        if(*s == '\0' || --n <= 0)
            return 0;
    }
    return *s - *t;
}