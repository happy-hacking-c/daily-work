#include <stdio.h>

#define swap(t, x, y) t temp; temp = x; x = y; y = temp;

int main()
{
    int a = 10;
    int b = 20;

    printf("swapBefore: a = %d, b = %d\n", a, b);
    swap(int, a, b);
    printf("swapAfter: a = %d, b = %d\n", a, b);

    return 0;
}


