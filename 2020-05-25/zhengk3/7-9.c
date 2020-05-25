
/**
 * 第35堂课作业：7-9
 * 郑凯
 * 2020年5月25日
 * */
#include <stdio.h>

int myIsUpper(int);

int myIsUpper(int c)
{
    if ( c >= 'A' && c <= 'Z')
       return 1;
    else
       return 0;

}


int main()
{
    int c;

    printf("Please input a character(input '~' can be exit):\n");
    while((c = getchar()) != '~')
    {
        
        if( c == '\n')
          continue;
        
        if(myIsUpper(c) == 1)
          printf("true\n");
        else
          printf("false\n");
        
    }

    printf("Exit Success\n");
    return 0;
}