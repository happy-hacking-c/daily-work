#include <stdio.h>
/* cat: concatenate files, version 2 */
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}
int main(int argc, char *argv[])
{
    fprintf(stdout,"Hello ");
    fprintf(stderr,"World!");

    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0]; /* program name for errors */
    if (argc == 1)        /* no args; copy standard input */
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                fprintf(stdout, "%s: out can't open %s\n", prog, *argv);
                fprintf(stderr, "%s: error can't open %s\n", prog, *argv);
                //exit(1);
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
    if (ferror(stdout))
    {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
    return 0;
}
