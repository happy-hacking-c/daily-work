
/**
 * 第35堂课示例：随机数
 * 郑凯
 * 2020年5月25日
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int rands;

    srand((unsigned)time(NULL));

    rands = rand();

    printf("rand number is %d\n", rands);

    printf("rand number2 is %d\n", rand());

    return 0;
}