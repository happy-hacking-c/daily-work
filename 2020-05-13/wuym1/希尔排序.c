#include "stdio.h"

int main() {
    int a[10] = {2, 4, 1, 3, 6, 7, 5, 0, 8, 9};

    for (int gap = 10 / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < 10; i++) {
            int j = i;
            int temp = a[j];
            if (a[j] < a[j - gap]) {
                while (j - gap >= 0 && temp < a[j - gap]) {
                    a[j] = a[j - gap];
                    j -= gap;
                }
                a[j] = temp;
            }
        }
    }

    printf("希尔排序:");
    for (size_t i = 0; i < 10; i++) {
        printf("%2d", a[i]);
    }
    printf("\n");

    return 0;
}