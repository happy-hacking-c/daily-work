
/**
 * 第36堂课示例：read&write函数
 * 郑凯
 * 2020年5月26日
 * */
#include <stdio.h>
#include <unistd.h>

int main() /* copy input to output */
{
    char buf[BUFSIZ];
    int n;
    while ((n = read(0, buf, BUFSIZ)) > 0)
        write(1, buf, n);
    return 0;
}