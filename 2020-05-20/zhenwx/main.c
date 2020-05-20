#include <stdio.h>

void downAdjust(int arr[], int parentIndex, int length) {
    int temp = arr[parentIndex];
    int childIndex = 2 * parentIndex + 1;

    while (childIndex < length) {
        if (childIndex + 1 < length && arr[childIndex + 1] > arr[childIndex]) {
            childIndex++;
        }
        if (temp >= arr[childIndex]) {
            break;
        }
        arr[parentIndex] = arr[childIndex];
        parentIndex = childIndex;
        childIndex = 2 * childIndex + 1;
    }

    arr[parentIndex] = temp;
}

void mySort(int arr[], int length) {
    for (int i = (length - 2) / 2; i >= 0; i--) {
        downAdjust(arr, i, length);
    }

    for (int i = length - 1; i > 0; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        downAdjust(arr, 0, i);
    }

    return;
}

int main() {
    int a[10], i;
    printf("输入10个数：\n");
    for (i = 0; i < 10; i++) scanf("%d", &a[i]);

    mySort(a, 10);

    printf("排序结果：\n");
    for (i = 0; i < 10; i++) printf("%5d", a[i]);
    printf("\n");

    return 0;
}