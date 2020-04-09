#include <stdio.h>

int any(char s1[], char s2[])
{
    int pos = -1;
    int i, n;
    i = 0;

    while (s1[i] != '\0')
    {
        n = 0;
        while (s2[n] != '\0')
        {
            if (s1[i] == s2[n])
            {
                printf("match:%c\n", s1[i]);
                pos = i;
                goto EXIT;
            }
            n++;
        }
        i++;
    }

EXIT:

    return pos;
}

int main()
{
    char s1[10] = "asdfwre";
    char s2[10] = "09876";
    printf("s1:%s\ns2:%s\nfirstPos:%d\n", s1, s2, any(s1, s2));
    return 0;
}