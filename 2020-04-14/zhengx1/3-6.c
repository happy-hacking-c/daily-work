#include <stdio.h>
#include <string.h>

//将原字符串顺序颠倒
void reverse(char line[])
{
    int tmp;
    int max = 0;
    
    while (line[max] != '\0') {
        max++;
    }
    
    for (int i = 0; i < max / 2; i++) {
        tmp = line[i];
        line[i] = line[max - i - 1];
        line[max - i - 1] = tmp;
    }
}


void itoa(int n ,char s[],int b){
	int i,sign;
	if ((sign =n)< 0)
	{
		n = -n;
		/* code */
	}
	i = 0;
	do{
		s[i++] = n%10 + '0';
	}while ((n/=10)>0);
	if (sign <0)
	{
		s[i++] = '-';
		/* code */
	}
	
	for (; i < b; ++i)
	{
		s[i] = 32;
		/* code */
	}
	
	s[i] = '\0';

	// printf("%s\n", s);
	reverse(s);
}



int main(int argc, char const *argv[])
{
    int n = -9180000;
    int b = 6;
    char s[100];
    itoa(n,s,b);
    printf("%s\n", s);
	/* code */
	return 0;
}