
#include <stdio.h>

int invert(unsigned x, int p,int n);

int bitvounts(unsigned x);

int main()
{
	
	int x = 15;
	int p = 3;
	int n = 3;
	printf("invert : %d\n",invert(x,p,n));

	printf("bitvounts : %d\n",bitvounts(x));

	return 0;
}


int invert(unsigned x, int p,int n)
{
	return x ^ (~(~0 << n) << (p+n-1));
}

int bitvounts(unsigned x){
	int i = 0;
	while (x != 0)
	{
		 (x &= (x - 1));
		 i++ ;
	}
	return i;
	
}
