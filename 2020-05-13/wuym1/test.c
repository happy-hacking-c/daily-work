#include "stdio.h"

int main() {
    union mixed
    {
        int a;
        float b;
        char c;
    };

    union mixed mix1;

    mix1.b = 911.3;
    mix1.a = 0b11111111;
    mix1.c = 's';

    printf("a=%d, b=%f, c=%c", mix1.a, mix1.b, mix1.c);
    
    return 0;
}