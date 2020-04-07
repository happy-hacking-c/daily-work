
/**
 * 输出EOF的值
 * 郑凯
 * 2020年04月05日17:29:38
 *
 * */

#include <stdio.h>

int main()
{
    int fahr;

    //输出
    printf("value is %d\n", getchar() != EOF);
    printf("value of EOF is %d\n", EOF);

    return 0;
}