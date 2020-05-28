//
// Created by cotton on 2020/5/28.
//

#include <stdio.h>
float cal(float x, float y) ;

int main() {
    printf("%f", cal(99, 6));
    return 0;
}

float cal(float x, float y) {
    if (x == y) return x;
    if (x < 1 || y < 1) return (float)0;
    if (x > y) {
        return cal((0.7 * x -3), 7) + cal(x, y- 8.4) + x + y + 1;
    } else {
        return cal(x/2, y-1) + cal(x-1, y/3) + x + y;
    }
}