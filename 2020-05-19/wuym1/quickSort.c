#include <stdio.h>

void swap(int a[], int i, int j);
void quickSort(int a[], int start, int end);

int main() {
    int a[10] = {2, 4, 1, 3, 6, 7, 5, 0, 8, 9};
    
    quickSort(a, 0, 9);

    printf("quick sort:");
    for (int i = 0; i < 10; i++) {
        printf("%2d", a[i]);
    }

    return 0;
}

void swap(int a[], int i, int j) {
    if (i != j) {
        a[i] += a[j];
        a[j] = a[i] - a[j];
        a[i] = a[i] - a[j];
    }
}

void quickSort(int a[], int start, int end) {
    if (start >= end) {
        return;
    }

    swap(a, start, (start + end) / 2);
    int last = start;
    for (int i = start + 1; i <= end; i++) {
        if (a[i] < a[start]) {
            swap(a, ++last, i);
        }
    }
    swap(a, start, last);
    quickSort(a, start, last - 1);
    quickSort(a, last + 1, end);
}