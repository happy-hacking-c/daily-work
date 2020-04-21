#include <stdio.h>
#include <string.h>

#define MAXLINES 3    /* max #lines to be sorted */
#define MAXLEN 1000 /* max length of any input line */


char *lineptr[MAXLINES]; /* pointers to text lines */
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);


int gline(char line[], int maxline);
/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *p[])
{
    int len, nlines;
    char line[MAXLEN];
    nlines = 0;
    while ((len = gline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines) {
            return maxlines;
        } else {
            line[len - 1] = '\0'; /* delete newline */
            p[nlines] = line;
            //strcpy(p[nlines], line);
            lineptr[nlines++] = p[nlines];
        }
    }
    return nlines;
}
int gline(char s[], int lim)
{
	int i; // 字符数
	int c; // 读取的字符
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		s[i] = c;
	}
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}
/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* sort input lines */
int main()
{
    int nlines; /* number of input lines read */
    char *p[MAXLINES];
    if ((nlines = readlines(lineptr, MAXLINES, p)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}
/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
