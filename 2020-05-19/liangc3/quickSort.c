//
// Created by cotton on 2020/5/19.
//
#include <stdio.h>
void quickSort(int a[], int start, int end);

int main() {
    int a[] = {220, 3, 45, 67, 12, 66, 17, 42, 9, 8};
    int len = (sizeof a) / (sizeof a[0]);
    quickSort(a, 0, len - 1);
    for (int i = 0; i < len; i++) {
        printf("%d\n", a[i]);
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
    if (start >= end)
        return;
    swap(a, start, (start+end)/2);
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

