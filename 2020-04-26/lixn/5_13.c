#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void tail(int n);
static int mygetline(char *s, int len);

int main(int argc, char *argv[])
{
    int n = 10;
    char *arg;
    while (--argc > 0)
    {
        arg = *(++argv);
        if (*arg == '-')
        {
            n = atoi(++arg);
        }
    }
    tail(n);
}

void tail(int n)
{
    int count = 0;
    char *lines[n];

    char s[MAXLINE];
    int w;
    char *p;

    while ((w = mygetline(s, MAXLINE)) != 0)
    {
        p = malloc(w);
        if (p == NULL)
        {
            printf("memory alloc error");
            return;
        }
        else
        {
            strcpy(p, s);

            if (count >= n)
            {
                free(lines[count % n]);
            }
            lines[count % n] = p;
            count++;
        }
    }

    int start = 0;
    int end = n;

    if (count >= n)
    {
        start = count;
        end = count + n;
    }

    for (; start < end; start++)
    {
        printf("%s\n", lines[start % n]);
        free(lines[start % n]);
    }
}

static int mygetline(char *s, int len)
{
    int i; // 字符数
	int c; // 读取的字符
	for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
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
