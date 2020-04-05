
/**
 * 温度转换程序
 * 郑凯
 * 2020年04月05日17:18:01
 *
 * */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    int fahr;

    //输出表头信息
    printf("The table of fahr to sheshi\n");

    for(fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
    }

    return 0;
}