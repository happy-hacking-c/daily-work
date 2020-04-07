#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[]);
int gline(char line[], int maxline);

int main()
{
	char line[MAXLINE];
	while (gline(line, MAXLINE) > 0)
	{
		reverse(line);
		printf("%s", line);
	}
	return 0;
}

void reverse(char s[])
{
	char t;
	int i, j;
	// 统计长度
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		i++;
	}
	i--;
	j = 0;
	while (j < i)
	{
		t = s[j];
		s[j] = s[i];
		s[i] = t;
		--i;
		++j;
	}
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