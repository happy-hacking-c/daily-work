#include <stdio.h>
#define MAXLINE 1000 /* 允许输入行的最大长度 */

int getoneline(char line[],int maxline);
void reverse(char old[],int len);


/* 反转输入行 */
int main(int argc, char const *argv[])
{
	/* code */
	int len; 
	char line[MAXLINE];

	if ((len = getoneline(line ,MAXLINE)) >0 ){
		reverse(line,len);
	}


	printf("%s\n", line);
	return 0;
	
}

//获取一行内容
int getoneline(char s[],int lim)
{
	int c,i;
	for (i=0;i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	 {
	 	s[i] = c;
	 	++i;
	 } 
	 s[i] = '\0';
	 return i;
}

//在原数组上反转
void reverse(char old[],int len)
{
	char tmp;
	for (int i = 0; i < len/2; ++i)
	{
		tmp = old[i];
		old[i] = old[len-i-2];
		old[len-i-2] =  tmp;
	}

}