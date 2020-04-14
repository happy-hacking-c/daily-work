//修改itoa函数，使得该函数可以接收三个参数。其中，第三个参数为最小字段宽度。
//为了保证转化后所得结果至少具有第三参数指定的最小宽度，必要时应在所得结果的左边添加一定的空格
#include <stdio.h>
#include <limits.h>

void itoa(int n, char s[], int x);
void reverse(char s[]);

int main()
{
    int n, x;
    n = INT_MIN;
    x = 20;
    char s[1024];
    itoa(n, s, x);
    printf("lenth = %d, itoa = '%s'\n", x, s);

    return 0;
}

void itoa(int n, char s[], int x)
{
    int sign, i;
    sign = n;
    i = 0;

    do {
        if (sign < 0)
            s[i++] = -(n % 10) + '0';
        else
            s[i++] = n % 10 + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);

    x--; //指定宽度的最后一位下标
    if (i < x) {
        //先将数据后移
        while (i >= 0)
            s[x--] = s[i--];
        //再补空格
        while (x >= 0)
            s[x--] = ' ';
    }
}

void reverse(char s[])
{
    int i, j, c;
    for (j = 0; s[j] != '\0'; j++);
    for (i = 0, j--; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}