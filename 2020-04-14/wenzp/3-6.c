#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void itoaa(int n, char s[], int b);
void reverse(char s[]);
int main()
{
	int num, bits;
	char str[100];
	printf("Please enter number, bits: ");
	scanf("%d %d", &num, &bits);
	itoaa(num, str, bits);
	printf("Result=");
	puts(str);
	system("pause");
	return 0;
}
void itoaa(int n ,char s[], int b)
{
	int i, sign;
	if ((sign=n)<0)
		n=-n;
	i=0;
	do{
		s[i++]=n%10+'0';
	}while ((n/=10)>0);
	if (sign<0)
		s[i++]='-';
	for (; i<b; s[i++]=' ');
	s[i]='\0';
	reverse(s);
}
void reverse(char s[])
{
	int c, i ,j;
	for (i=0, j=strlen(s)-1; i<j; i++, j--){
		c=s[i], s[i]=s[j], s[j]=c;
	}
}


