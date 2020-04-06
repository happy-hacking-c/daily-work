
#include <stdio.h>

#define MAXLINE 1000

//练习119编写函数 reverse(s)、将字符s中的字符顺序倒过米。使用该函数编写一个程序、每次颠倒一个输入行中的字符顺序

void reverse(char line[],int end);
int get_line(char line[], int maxline);

int main()
{
	char line[MAXLINE];
    int str_len;
	while ((str_len = get_line(line, MAXLINE)) > 0)
	{
        reverse(line,str_len);
		printf("%s", line);
	}
	return 0;
}


//颠倒顺序 
void reverse(char line[],int end){
    int start;
    char tmp;
    --end;
    start = 0;
    
    while (end > start)
    {
        tmp = line[start];
        line[start] = line[end];
        line[end] = tmp;

        ++start;
        --end;
    }
}

//读取数据
int get_line(char line[], int maxline){
    int i,c;
	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		line[i] = c;
	}
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}

