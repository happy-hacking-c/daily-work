#include <stdio.h>

void _strncpy(char *s, char *t, int len)
{
    while (len-- > 0 && (*s++ = *t++));
}

void _strncat(char *s, char *t, int len)
{
    while (*++s != '\0');
    while (len-- > 0 && (*s++ = *t++));
    
    *s = '\0';
}

int _strncmp(char *s, char *t, int len)
{
    for (; *s == *t && len > 0; s++, t++, len--) {
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}

int main(int argc, char const *argv[])
{
    /* code */
    char s[] = "test1 hello world";
    char t[] = "ntest2";
    int len = 6;

    _strncpy(s, t, len);

    printf("%s\n%s\n", s, t);
    printf("%d", _strncmp(s, t, len));

    _strncat(s, t, len);
    printf("%s\n%s\n", s, t);

    return 0;
}
