#include <stdio.h>
#include <unistd.h>

#undef getchar

int getchar(void)
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;
    if (n == 0)
    { /* buffer is empty */
        n = read(0, buf, sizeof(buf));
        bufp = buf;
        printf("%d", n);
    }
    printf("%d", n);
    return (--n >= 0) ? (unsigned char)*bufp++ : EOF;
}

int main()
{
    char c;
    while ((c = getchar()) != EOF)
    {
        printf("%c\n", c);
    }

    return 0;
}
