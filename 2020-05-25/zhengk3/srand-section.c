
/**
 * 第35堂课示例：有区间的随机数
 * 例如：100~150之间的数字
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

    rands = rand() % 51 + 100;

    printf("rand number is %d\n", rands);

    return 0;
}