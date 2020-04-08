#include <stdio.h>
#include <limits.h>

long power(int, int);

int main() {
    printf("    signed char value range is from %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("cal signed char value range is from -%ld to %ld\n", power(2, sizeof(char)*8-1), power(2, sizeof(char)*8-1)-1);

    printf("    unsigned char value range is from %d to %d\n", 0, UCHAR_MAX);
    printf("cal unsigned char value range is from %d to %ld\n", 0, power(2, sizeof(char)*8)-1);

    printf("    signed short value range is from %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("cal signed short value range is from -%ld to %ld\n", power(2, sizeof(short)*8-1), power(2, sizeof(short)*8-1)-1);

    printf("    unsigned short value range is from %d to %d\n", 0, USHRT_MAX);
    printf("cal unsigned short value range is from %d to %ld\n", 0, power(2, sizeof(short)*8)-1);

    printf("    signed int value range is from %d to %d\n", INT_MIN, INT_MAX);
    printf("cal signed int value range is from -%ld to %ld\n", power(2, sizeof(int)*8-1), power(2, sizeof(int)*8-1)-1);

    printf("    unsigned int value range is from %d to %u\n", 0, UINT_MAX);
    printf("cal unsigned int value range is from %d to %ld\n", 0, power(2, sizeof(unsigned int)*8)-1);

    printf("    signed long value range is from %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("cal signed long value range is from -%ld to %ld\n", power(2, sizeof(long)*8-1), power(2, sizeof(long)*8-1)-1);

    printf("    unsigned long value range is from %d to %ld\n", 0, ULONG_MAX);
    printf("cal unsigned long value range is from %d to %ld\n", 0, power(2, sizeof(long)*8)-1);
}

long power(int base, int n) {
    long p = 1;
    int i;
    for (i=0; i<n; i++) {
        p = p * base;
    }
    return p;
}

