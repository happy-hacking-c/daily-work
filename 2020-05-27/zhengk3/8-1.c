
/**
 * 第37堂课示例：习题8-1
 * 郑凯
 * 2020年5月27日
 * */
#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2


void error(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    fprintf((FILE *)STDERR, "error: ");

    vfprintf((FILE *)STDERR, fmt, args);
    fprintf((FILE *)STDERR, "\n");
    va_end(args);
    exit(1);
}


void filecopy(int ifd, int ofd)
{
    int n;
    char buf[BUFSIZ];

    /* read and write using the system calls. */

    while ((n = read(ifd, buf, BUFSIZ)) > 0)
        if (write(ofd, buf, n) != n)
        {
            error("cat: write error");
        }
}



int main(int argc, char *argv[])
{
    int fd;

    if (argc == 1)
    {
        filecopy(STDIN, STDOUT);
    }
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY)) == -1)
            {
                error("cat:can't open %s", *argv);
            }
            else
            {
                filecopy(fd, STDOUT);
                close(fd);
            }
    return 0;
}