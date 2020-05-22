#include <stdio.h>
 #include <stdlib.h>

void mySort(int arr[], int length) {
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