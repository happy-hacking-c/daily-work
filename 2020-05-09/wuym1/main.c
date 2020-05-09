#include "stdio.h"

int main() {
    int i, j, sortman;
    int a[10] = {2, 4, 1, 3, 6, 7, 5, 0, 8, 9};

    for (i = 1; i < 10; i++) {
        sortman = a[i];
        for (j = i - 1; j >= 0 && a[j] > sortman; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = sortman;
    }

    printf("sortman:");
    for (size_t i = 0; i < 10; i++) {
        printf("%2d", a[i]);
    }
    printf("\n");

    return 0;
}