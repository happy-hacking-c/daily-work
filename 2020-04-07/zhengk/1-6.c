
/**
 * 验证 getchar()!= EOF的值
 * 郑凯
 * 2020年04月05日17:29:38
 *
 * */

#include <stdio.h>

int main()
{
    int fahr;

    //输出表头信息
    printf("value is %d\n", getchar() != EOF);

    return 0;
}