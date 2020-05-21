#include "stdio.h"

int main(int argc, char* argv[]) {
    int arr[20] = {5, 6, 7, 8, 9, 0, 1, 2, 3, 4};
    int length = (sizeof arr) / (sizeof arr[0]);
    int max = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucket[max + 1];
    for (int i = 0; i < length; i++) {
        bucket[arr[i]] = 0;
    }
    for (int i = 0; i < length; i++) {
        bucket[arr[i]]++;
    }

    int k = 0;
    for (int i = 0; i < max + 1; i++) {
        if (bucket[i] > 0) {
            int j = bucket[i];
            while (j--) {
                arr[k++] = i;
            }
        }
    }

    for (int i = 0; i < length; i++) {
        printf("%2d", arr[i]);
    }

    return 0;
}