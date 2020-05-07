#include "stdio.h"

int main() {
    int a[10] = {1, 3, 6, 8, 4, 5, 9, 2, 0, 7};

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
        printf("%d ", a[i]);
    }

    return 0;
}