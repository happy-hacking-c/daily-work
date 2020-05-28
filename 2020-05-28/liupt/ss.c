#include <stdio.h>
#include <stdlib.h>

float ffunc(float x, float y);

float ffunc(float x, float y) {
    float res;
    
    if (x == y) {
        res = x;
    } else if (x < 1 || y < 1) {
        res = 0;
    } else if (x > y && y >= 1) {
        res = ffunc(0.7 * x - 3, y) + ffunc(x, y - 8.4) + x + y + 1;
    } else if (y > x && x >= 1) {
        res = ffunc(x / 2, y - 1) + ffunc(x - 1, y / 3) + x + y;
    }

    return res;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("参数不能小于两个\n");
        return 1;
    }

    float x, y;
    x = atof(argv[1]);
    y = atof(argv[2]);

    if (x <= 0) {
        printf("第一个参数必须大于0\n");
        return 1;
    }

    if (y >= 100) {
        printf("第二个参数必须小于100\n");
        return 1;
    }

    printf("x = %.4f, y = %.4f, res = %.2f\n", x, y, ffunc(x, y));
    return 0;
}
