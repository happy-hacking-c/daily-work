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
    printf("SCHAR_MAX:%d, SCHAR_MIN:%d, UCHAR_MAX:%d\n", SCHAR_MAX, SCHAR_MIN, UCHAR_MAX);
    printf("SHRT_MAX:%d, SHRT_MIN:%d, USHRT_MAX:%d\n", SHRT_MAX, SHRT_MIN, USHRT_MAX);
    printf("INT_MAX:%d, INT_MIN:%d, UINT_MAX:%d\n", INT_MAX, INT_MIN, UINT_MAX);
    printf("LONG_MAX:%ld, LONG_MIN:%ld, ULONG_MAX:%ld\n", LONG_MAX, LONG_MIN, ULONG_MAX);
    
    printf("直接计算:\n");
    printf("不知道咋弄\n");
}
