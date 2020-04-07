#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	/* code */
	printf("signed   char  取值范围: %-20d ~ %-10d\n",CHAR_MAX,CHAR_MIN);
	printf("signed   short 取值范围: %-20d ~ %-10d\n",SHRT_MAX,SHRT_MIN);
	printf("signed   int   取值范围: %-20d ~ %-10d\n",INT_MAX ,INT_MIN);
	printf("signed   long  取值范围: %-20ld ~ %-10ld\n",LONG_MAX ,LONG_MIN);
	printf("unsigned char  取值范围: %-20u ~ %-10u\n",UCHAR_MAX ,0);
	printf("unsigned short 取值范围: %-20u ~ %-10u\n",USHRT_MAX,0);
	printf("unsigned int   取值范围: %-20u ~ %-10u\n",UINT_MAX ,0);
	printf("unsigned long  取值范围: %-20lu ~ %-10lu\n",ULONG_MAX ,0ul);

	signed char a ;

	return 0;
}