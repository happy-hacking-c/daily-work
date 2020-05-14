#include "stdio.h"

void myMergeSort(int a[], int start, int end);
void myMerge(int a[], int start, int mid, int end);

int main() {
    int a[10] = {2, 4, 1, 3, 6, 7, 5, 0, 8, 9};

    myMergeSort(a, 0, 9);

    printf("Result:");
    for (size_t i = 0; i < 10; i++) {
        printf("%2d", a[i]);
    }
    printf("\n");

    return 0;
}

void myMergeSort(int a[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        myMergeSort(a, start, mid);
        myMergeSort(a, mid + 1, end);
        myMerge(a, start, mid, end);
    }
}

void myMerge(int a[], int start, int mid, int end) {
    int length = end - start + 1;
    int tempArr[length];
    int p1 = start, p2 = mid + 1, p = 0;
    while (p1 <= mid && p2 <= end) {
        if (a[p1] <= a[p2]) {
            tempArr[p++] = a[p1++];
        } else {
            tempArr[p++] = a[p2++];
        }
    }
    while (p1 <= mid) {
        tempArr[p++] = a[p1++];
    }
    while (p2 <= end) {
        tempArr[p++] = a[p2++];
    }
    for (size_t i = 0; i < length; i++) {
        a[i + start] = tempArr[i];
    }
}