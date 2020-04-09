//
// Created by junhai on 2020/4/8.
//

#include <stdio.h>
#include <limits.h>

int main(){
        printf("char max : %d  min : %d\n",CHAR_MAX, CHAR_MIN);
        printf("unchar max : %u\n",UCHAR_MAX);
        printf("int max : %d  min : %d\n",INT_MAX, INT_MIN);
        printf("unsigned int max : %d\n",UINT_MAX);
        printf("long max : %ld  min : %ld\n",LONG_MAX, LONG_MIN);
        printf("unsigned long max : %lu\n",ULONG_MAX);
        printf("short max : %d  min : %d\n",SHRT_MAX, SHRT_MIN);
        printf("unsigned short max : %d\n", USHRT_MAX);
        return 0;
}

