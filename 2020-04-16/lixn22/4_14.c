#include <stdio.h>

#define swap(t, x, y) t tmp; tmp = x; x = y; y = tmp;

int main()
{
    int a = 10;
    int b = 20;

    swap(int, a, b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
