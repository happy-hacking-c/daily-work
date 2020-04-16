//
// Created by cotton on 2020/4/16.
//

#include <stdio.h>
#define swap(t,x,y) t tmp = x; x = y; y = tmp;

int main() {
//    char t[] = "int";
    int x = 2;
    int y = 3;
    swap(int,x,y);
    printf("%d\n", x);
    printf("%d\n", y);
}

