#include <stdio.h>

void mysort(char *a, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;
    mysort(a, start, mid);
    mysort(a, mid + 1, end);

    Merge(a, start, mid, end);
}

void Merge(char *a, int start, int mid, int end) {
    int *temp = (int *)malloc((end - start + 1) * sizeof(int));
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= end) {
        temp[k++] = a[j++];
    }

    for (i = 0; i < k; i++) {
        a[start + i] = temp[i];
    }

    free(temp);
}

int main() {
    int a[10], i;
    printf("输入10个数：\n");
    for (i = 0; i < 10; i++) scanf("%d", &a[i]);

    mysort(a, 0, 10);

    printf("排序结果：\n");
    for (i = 0; i < 10; i++) printf("%5d", a[i]);
    printf("\n");

    return 0;
}