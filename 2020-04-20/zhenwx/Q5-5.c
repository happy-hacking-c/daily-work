#include <stdio.h>

void mystrncpy(char *s, char *t, int n)
{
    while ((*s++ = *t++) && --n > 0)
        ;
    while (n-- > 0)
    {
        *s++ = '\0';
    }
}

void mystrncat(char *s, char *t)
{
    while (*s++);
    if (*s--) *s = *s;
    while ((*s++ = *t++));
}

int mystrncmp(char *s, char *t, int n)
{
    for (;*s && *s == *t; ++s, ++t)
    {
        if (--n <= 0)
            return 0;
    }
    return *s - *t;
}

int main()
{
    char s[100] = "";
    char t[100] = "asdfghjkl";

    mystrncpy(s, t, 5);
    printf("mystrncpy() = %s\n", s);

    mystrncat(s, t);
    printf("mystrncat() = %s\n", s);

    printf("mystrncmp() = %d\n", mystrncmp(s, t, 5));

    return 0;
}
