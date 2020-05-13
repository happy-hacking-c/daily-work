#include <stdio.h>

int mysort(int s[], int len) {
    int i, j,temp, step;
    for (step = len / 2; step >= 1; step /= 2) {
        for (i = 0 + step; i < len; i += step) {
            temp = s[i];
            j = i - step;
            while (j >= 0 && s[j] > temp) {
                s[j + step] = s[j];
                j -= step;
            }
            s[j + step] = temp; 
        }
    }

    return 0;
}

int main() {
    int a[10], i;
    printf("输入10个数：\n");
    for (i = 0; i < 10; i++) scanf("%d", &a[i]);

    mysort(a, 10);

    printf("排序结果：\n");
    for (i = 0; i < 10; i++) printf("%5d", a[i]);
    printf("\n");

    return 0;
}