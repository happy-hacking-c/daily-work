#include "stdio.h"

int main(int argc, char* argv[]) {
    int arr[10] = {5, 6, 7, 8, 9, 0, 1, 2, 3, 4};
    int length = (sizeof arr) / (sizeof arr[0]);
    printf("基数排序：");
    for (int i = 0; i < length; i++) {
        printf("%2d", arr[i]);
    }
    return 0;
}