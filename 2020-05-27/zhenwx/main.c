#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp) {
    int c;
    while ((c = getc(ifp)) != EOF) putc(c, ofp);
}

void filecopy0(int ifd, int ofd)
{
    int n;
    char buf[BUFSIZ];

    while ((n = read(ifd, buf, BUFSIZ)) > 0)
        if (write(ofd, buf, n) != n)
        {
            printf("cat: write error");
        }
}


int main(int argc, char *argv[]) {
    FILE *fp;
    void filecopy(FILE *, FILE *);

    int fd;

    if (argc == 1) { /* no args; copy standard input */
        filecopy(stdin, stdout);
    } else {
        while (--argc > 0)

            /* cat: concatenate files, version 1 */
            // cc -o cat 2020-05-27/zhenwx/main.c
            if (strcmp(argv[0], "./cat") == 0) {
                if ((fp = fopen(*++argv, "r")) == NULL) {
                    printf("cat: can't open %s\n", *argv);
                    return 1;
                } else {
                    filecopy(fp, stdout);
                    fclose(fp);
                }

            // cc -o cat0 2020-05-27/zhenwx/main.c
            } else {
                if ((fd = open(*++argv, O_RDONLY)) == -1) {
                    printf("cat: can't open %s\n", *argv);
                } else {
                    filecopy0(fd, 1);
                    close(fd);
                }
            }
    }

    return 0;
}