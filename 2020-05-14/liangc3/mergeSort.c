//
// Created by cotton on 2020/5/14.
//
#include <stdio.h>
void mergeSort(int a[], int r[], int start, int end);

int main() {
    int a[] = {220, 3, 45, 67, 12, 66, 17, 42, 9, 8};
    int len = (sizeof a) / (sizeof a[0]);
    int b[len];
    mergeSort(a, b, 0, len-1);
    for (int i = 0; i<len; i++) {
        printf("%d\n",a[i]);
    }
    return 0;
}

void mergeSort(int a[], int r[], int start, int end) {
    if (start >= end) {
        return;
    }
    int len = end - start;
    int mid = (len >> 1) + start;
    int start1 = start;
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;
    mergeSort(a, r, start1, end1);
    mergeSort(a, r, start2, end2);
    int k = start;
    while(start1 <= end1 && start2 <= end2)
        r[k++] = (a[start1] < a[start2]) ? a[start1++] : a[start2++];
    while(start1 <= end1)
        r[k++] = a[start1++];
    while(start2 <= end2)
        r[k++] = a[start2++];
    for (k = start; k <= end; k++) {
        a[k] = r[k];
    }
}
