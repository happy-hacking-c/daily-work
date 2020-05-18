#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	int c;
	/* code */
	if (strcmp(argv[0],"tolower")== 0)
	{
		while ((c = getchar()) != EOF)
			putchar(tolower(c));
	}else{
		while ((c = getchar()) != EOF)
			putchar(toupper(c));
	}

	return 0;
}