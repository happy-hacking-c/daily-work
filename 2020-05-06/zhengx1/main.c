#include <stdio.h>

int main(int argc, char const *argv[])
{
	char a,b,c;
	a = 'a';
	b = 'a';
	c = 'a';
    char *p[] = {&a,&b,&c};
    for (int i = 0; i < 3; ++i)
    {
    	printf("%c\n", *p[i]);
    	/* code */
    }

	/* code */
	return 0;
}