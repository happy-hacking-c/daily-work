#include <stdio.h>

#define swap(t, x, y) { t _z;   \
                        _z = y; \
                        y = x;  \
                        x = _z; }

int main() {
    int a = 1;
    int b = 2;
    swap(int ,a,b)
    printf("%d,%d",a,b);
    return 0;
}
