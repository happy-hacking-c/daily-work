#include "stdio.h"

int main() {
    int a[10] = {2, 4, 1, 3, 6, 7, 5, 0, 8, 9};

    for (size_t i = 0; i < 10; i++) {
        int min = i;
        for (size_t j = i + 1; j < 10; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    for (size_t i = 0; i < 10; i++) {
        printf("%3d", a[i]);
    }
    printf("\n");

    return 0;
}