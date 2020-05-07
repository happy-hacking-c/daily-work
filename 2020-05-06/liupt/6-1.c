#include <stdio.h>
#include "getchar.c"
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(keytab[0]))

/* getword: get next word or character from input */

struct key
{
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "define", 0,
    "include", 0,
    /* ... */
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0};

int getword(char *word, int lim);
int binsearch(char *word, struct key tab[], int n);
int comment(void);

int main()
{
    int n;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n",
                   keytab[n].count, keytab[n].word);
    return 0;
}

int getword(char *word, int lim)
{
    int c, d;
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;

    if (isalpha(c) || c == '_' || c == '#')
    {
        for (; --lim > 0; w++)
            if (!isalnum(*w = getch()) && *w != '_')
            {
                ungetch(*w);
                break;
            }
    }
    else if (c == '\'' || c == '\"')
    {
        for (; --lim > 0; w++)
            if ((*w = getch()) == '\\')
            {
                *++w = getch();
            }
            else if (*w == c)
            {
                w++;
                break;
            }
            else if (*w == EOF)
            {
                break;
            }
    }
    else if (c == '/')
    {
        d = getch();
        if (d == '/')
        {
            while ((c = getch()) != EOF)
                ;
        }
        else if (d == '*')
        {
            c = comment();
        }
        else
        {
            ungetch(c);
        }
    }

    *w = '\0';
    return c;
}

int comment(void)
{
    int c;
    while ((c = getch()) != EOF)
    {
        if (c == '*')
        {
            if ((c = getch()) == '/')
            {
                break;
            }
            else
            {
                ungetch(c);
            }
        }
    }
    return c;
}
/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
