//
//  type_range.c
//  wuym1
//
//  Created by min on 2020/4/8.
//  Copyright © 2020 min. All rights reserved.
//

#include "type_range.h"
#include "limits.h"

void type_range() {
    printf("直接打印标准头文件的相应值:\n");
    printf("SCHAR_MAX:%d, SCHAR_MIN:%d, UCHAR_MAX:%u\n", SCHAR_MAX, SCHAR_MIN, UCHAR_MAX);
    printf("SHRT_MAX:%d, SHRT_MIN:%d, USHRT_MAX:%u\n", SHRT_MAX, SHRT_MIN, USHRT_MAX);
    printf("INT_MAX:%d, INT_MIN:%d, UINT_MAX:%u\n", INT_MAX, INT_MIN, UINT_MAX);
    printf("LONG_MAX:%ld, LONG_MIN:%ld, ULONG_MAX:%lu\n", LONG_MAX, LONG_MIN, ULONG_MAX);
    
    printf("直接计算:\n");
    printf("SCHAR_MAX:%d\n", (char)((unsigned char)~0>>1));
    printf("SCHAR_MIN:%d\n", -(char)((unsigned char)~0>>1)-1);
    printf("UCHAR_MAX:%u\n", (unsigned char)~0);
    printf("SHRT_MAX:%d\n", (short)((unsigned short)~0>>1));
    printf("SHRT_MIN:%d\n", -(short)((unsigned short)~0>>1)-1);
    printf("USHRT_MAX:%u\n", (unsigned short)~0);
    printf("INT_MAX:%d\n", (int)((unsigned int)~0>>1));
    printf("INT_MIN:%d\n", -(int)((unsigned int)~0>>1)-1);
    printf("UINT_MAX:%u\n", (unsigned int)~0);
    printf("LONG_MAX:%ld\n", (long)((unsigned long)~0>>1));
    printf("LONG_MIN:%ld\n", -(long)((unsigned long)~0>>1)-1);
    printf("ULONG_MAX:%lu\n", (unsigned long)~0);
}
