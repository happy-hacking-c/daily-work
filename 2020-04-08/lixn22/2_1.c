#include <stdio.h>
#include <limits.h>

void main(){
    printf("char max : %d  min : %d\n",CHAR_MAX, CHAR_MIN);
    printf("unchar max : %u\n",UCHAR_MAX);
    printf("int max : %d  min : %d\n",INT_MAX, INT_MIN);
    printf("unsigned int max : %lu\n",UINT_MAX);
    printf("long max : %ld  min : %ld\n",LONG_MAX, LONG_MIN);
    printf("unsigned long max : %lu\n",ULONG_MAX);
    printf("short max : %ld  min : %ld\n",SHRT_MAX, SHRT_MAX);
    printf("unsigned short max : %lu\n", USHRT_MAX);
}