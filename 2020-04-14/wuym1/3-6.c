#include "stdio.h"
#include "string.h"

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[], int size)
{
    int i, sign;

    if ((sign = n) < 0)
    {
        n = -n;
    }
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
    {
        s[i++] = '-';
        size -= 1;
    }
    if (i < size)
    {
        for (size_t j = 0; j < size - i; j++)
        {
            s[i++] = ' ';
        }
    }
    
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[10];
    itoa(16777, s, 10);
    printf("%s\n", s);
    return 0;
}