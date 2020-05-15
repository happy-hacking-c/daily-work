
#include<stdio.h>
#include<string.h>
#include<ctype.h>


int main(int argc,char *argv[])
{
    int c;

    //./a.out
    if(strcmp(argv[0],"./lower")==0)
        while((c=getchar()) != EOF)
            putchar(tolower(c));
    else
        while((c=getchar()) != EOF)
            putchar(toupper(c));

    return 0;
}
