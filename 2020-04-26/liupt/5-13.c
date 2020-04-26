#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int agetline(char *line, int max);
/* find: print lines that match pattern from 1st arg */

int main(int argc, char *argv[])
{
    char lines[MAXLINE][MAXLINE];

    long lineno = 0;
    int c, number = 10, found = 0;
    int printno = 0;
    while (--argc > 0 && (*++argv)[0] == '-'){
        while ((c = (*++argv[0])))
            switch (c)
            {
            case 'n':
                number = atoi(*++argv);
                argc --;
                printf("number %d\n",number);
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
    }
       
    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else if (number > MAXLINE)
        number = MAXLINE;
    while (agetline(lines[lineno], MAXLINE) > 0)
    {
        lineno++;
        found++;
    }
    printno = lineno - number >= 0 ? lineno - number : 0;
    while (printno < lineno)
    {
        printf("%d:", printno);
        printf("%s", lines[printno]);
        printno ++;
        /* code */
    }

    return found;
}

int agetline(char *s, int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}