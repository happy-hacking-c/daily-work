
/**
 * 第二堂课作业(64位版)
 * 郑凯
 * 2020年4月7日22:57:34
 * 需要讨论的问题：
 * 1、%d、%ld、%u、%lu的区别；
 * 2、不同类型的取值范围跟机器是否有关系？
 * 3、unsigned的最小值为什么最后要-1才对？
 * 4、进制有哪些，怎么互相转换？
 * 5、什么是采用二级制补码的机器？
 * */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{

    //从标准头文件中输出
    printf("The values from standard file:\n");
    printf("------------------------------\n");
    printf("signed char: %d ~ %d\n",SCHAR_MIN , SCHAR_MAX);
    printf("unSigned char: %d ~ %u\n",0 , UCHAR_MAX);
    printf("signed short: %d ~ %d\n",SHRT_MIN, SHRT_MAX);
    printf("unSigned short: %d ~ %u\n",0 , UCHAR_MAX);
    printf("signed int: %d ~ %d\n",INT_MIN, INT_MAX);
    printf("unSigned int: %d ~ %u\n",0 , UCHAR_MAX);
    printf("signed long: %lld ~ %lld\n",LONG_LONG_MIN , LONG_LONG_MAX);
    printf("unSigned long: %d ~ %llu\n",0 , ULLONG_MAX);
    printf("------------------------------\n");

    //直接计算
    printf("The values from calculate:\n");
    printf("------------------------------\n");
    printf("signed char: %d ~ %d\n", -(char)((unsigned char) ~0 >> 1) - 1, (char)((unsigned char) ~0 >> 1));
    printf("unSigned char: %d ~ %u\n",0 , (unsigned char) ~0);
    printf("signed short: %d ~ %d\n",-(short)((unsigned short) ~0 >> 1) - 1, (short)((unsigned short) ~0 >> 1));
    printf("unSigned short: %d ~ %u\n",0 , (unsigned short) ~0);
    printf("signed int: %d ~ %d\n",-(int)((unsigned int) ~0 >> 1) - 1, (int)((unsigned int) ~0 >> 1));
    printf("unSigned int: %d ~ %u\n",0 ,(unsigned int) ~0);
    printf("signed long: %ld ~ %ld\n",-(long long)((unsigned long long) ~0 >> 1) - 1, (long long)((unsigned long long) ~0 >> 1));
    printf("unSigned long: %d ~ %lu\n",0 ,(unsigned long long) ~0);


    //查看类型占用字节数
    long long a;
    printf("%ld", sizeof a);
    return 0;



}