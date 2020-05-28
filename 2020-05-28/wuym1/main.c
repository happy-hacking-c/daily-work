#include <stdio.h>
#include <stdlib.h>

double fxy(double x, double y) {
    if (x == y) {
        return x;
    } else if (x < 1 || y < 1) {
        return 0;
    } else if (x > y && y >= 1) {
        return fxy(0.7 * x - 3, y) + fxy(x, y - 8.4) + x + y + 1;
    } else {
        return fxy(x / 2, y - 1) + fxy(x - 1, y / 3) + x + y;
    }
}

int main(int argc, char* argv[]) {
    printf("%f", fxy(atof(argv[1]), atof(argv[2])));
    return 0;
}
