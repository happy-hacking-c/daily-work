
/**
 * 温度转换程序(摄氏温度转华氏温度)
 * 郑凯
 * 2020年04月05日17:23:36
 *
 * */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    int celsius;

    //输出表头信息
    printf("The table of Celsius to fahr\n");

    for(celsius = LOWER; celsius <= UPPER; celsius += STEP) {
        printf("%3d %6.1f\n", celsius, ((9.0 * celsius) / 5.0 ) + 32.0);
    }

    return 0;
}