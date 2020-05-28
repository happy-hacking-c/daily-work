#include <stdio.h>
#include <stdlib.h>

float cal(float x, float y) {    
    if (x == y) return res = x;
    if (x < 1 || y < 1) return res = 0;
    if (x > y >= 1) return res = cal(0.7 * x - 3, y) + cal(x, y - 8.4) + x + y + 1;
    if (y > x >= 1) return cal(x / 2, y - 1) + cal(x - 1, y / 3) + x + y;
}

int main(int argc, char const *argv[]) {
    printf("%.2f\n", cal(atof(argv[1]), atof(argv[2])));
    return 0;
}
