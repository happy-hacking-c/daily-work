#include <stdio.h>
#include <string.h>

int any(char [],char[]);

int main(int argc, char const *argv[])
{
	/* code */
	char s1[] = "abcdefg";
	char s2[] = "zzzzzzzgz";
	int p = any(s1,s2);
	printf("第一个字符位置%d",p);
	return 0;
}


int any(char s1[],char s2[])
{
	int i,j;
	while (s1[i] != '\0')
	{
		j = 0;	
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
			{
				return i;
			}
			j++;
			/* code */
		}
		i++;
	}
	return -1;
}