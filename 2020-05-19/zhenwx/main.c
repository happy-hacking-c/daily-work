#include <stdio.h>

void quickSort(int arr[], int low, int high) {
    int first = low;
    int last = high;
    int key = arr[first];
    if (low >= high) return;

    while (first < last) {
        while (first < last && arr[last] > key) {
            last--;
        }
        arr[first] = arr[last];

        while (first < last && arr[first] < key) {
            first++;
        }
        arr[last] = arr[first];
    }

    arr[first] = key;

    quickSort(arr, low, first - 1);
    quickSort(arr, first + 1, high);

    return;
}

int main() {
    int a[10], i;
    printf("输入10个数：\n");
    for (i = 0; i < 10; i++) scanf("%d", &a[i]);

    quickSort(a, 0, 9);

    printf("排序结果：\n");
    for (i = 0; i < 10; i++) printf("%5d", a[i]);
    printf("\n");

    return 0;
}