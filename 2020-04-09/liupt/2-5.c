
#include <stdio.h>

int any(char ch1[], char ch2[]);

int main()
{
	char ch1[12] = "32312414sda";
	char ch2[8] = "asdfghj";
	int pos = any(ch1,ch2);
	printf("postion : %d\n",pos);
	return 0;
}


int any(char ch1[], char ch2[])
{
	int i,j;
	i = 0;
	while (ch1[i] != '\0' )
	{
		j = 0;
		while (ch2[j] != '\0')
		{
			if(ch2[j] == ch1[i]){
				return i;
			}
			j++;
		}
		i++;
	}
	
	return -1;
}

