
/**
 * 第二堂课作业
 * 郑凯
 * 
 * */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{

    //从标准头文件中输出
    printf("The values from standard file:\n");
    printf("------------------------------\n");
    printf("signed char: %d\n",SCHAR_MAX);
    printf("unSigned char: %d\n",UCHAR_MAX);
    printf("signed short: %d\n",SHRT_MAX);
    printf("unSigned short: %d\n",USHRT_MAX);
    printf("signed int: %d\n",INT_MAX);
    printf("unSigned int: %d\n",UINT_MAX);
    printf("signed long: %d\n",LONG_MAX);
    printf("unSigned long: %d\n",ULONG_MAX);
    printf("------------------------------\n");

    //直接计算
    printf("The values from calculate:\n");
    printf("------------------------------\n");

    return 0;



}