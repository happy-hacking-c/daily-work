
/**
 * 第二堂课作业：温度转换函数
 * 郑凯
 * 2020年4月7日22:58:35
 * */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fToC(float f);

float fToC(float f)
{
    return (5.0/9.0) * (f - 32);
}

int main()
{
    int fahr;

    //输出表头信息
    printf("The table of fahr to celsius\n");

    for(fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%3d %6.1f\n", fahr, fToC(fahr));
    }

    return 0;
}
