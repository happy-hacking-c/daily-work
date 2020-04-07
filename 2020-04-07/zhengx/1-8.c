#include <stdio.h>
int main(int argc, char const *argv[])
{
	/* code */
	int c,nl,sp,tab;
	nl = 0;
	while ((c = getchar()) != EOF)
	{

		if (c == '\n')
		{
			++nl;
			/* code */
		}
		if (c == ' ')
		{
			++sp;
			/* code */
		}
		if (c == '\t')
		{
			++tab;
			/* code */
		}


	}
	printf("newline:%d space:%d tab:%d\n", nl,sp,tab);


	return 0;
}