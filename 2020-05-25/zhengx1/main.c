#include <stdio.h>

#define isupper(c) ((c) >= 'A' && (c) <= 'Z') ? 1 : 0


int main(int argc, char const *argv[])
{
	/* code */
	if (argc>1)
	{
		printf("%d\n", isupper(argv[1][0]));
		/* code */
	}
	
	return 0;
}

/*int isupper(char c){
    if(c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}*/