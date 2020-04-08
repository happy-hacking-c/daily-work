
#include <stdio.h>


int main()
{
	signed char schar = 0;
	unsigned char unchar = 0;
	signed short sshort = 0;
	unsigned short unshort = 0;
	signed int sint = 0;
	unsigned int unint = 0;
	signed long slong = 0;
	unsigned long unlong = 0;
	
	printf("cahr : +/- %d \n",(char)((unsigned char) ~schar >> 1));
	printf("unchar : %d \n", (unsigned char) ~unchar);

	printf("sshort : +/- %d \n",(short)((unsigned short) ~sshort >> 1));
	printf("unshort : %d \n",(unsigned short) ~unshort);

	printf("sint : +/- %d \n",(int)((unsigned int) ~sint >> 1));
	printf("unint : %u \n", (unsigned int) ~unint);

	printf("slong : +/- %ld \n",(long)((unsigned long) ~slong >> 1));
	printf("unlong : %lu \n", (unsigned long) (~unlong));
	return 0;
}


