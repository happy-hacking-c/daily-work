#include <stdio.h>

int insort(int s[], int n) {
    for (int i = 1; i < n; i++) {
        // 有序序列的最后一个元素位置
        int pos = i - 1;

        // 保存待排序元素的值
        int tmp = s[i];

        // 有序集合中的元素 大于 待排元素 
        while (pos >= 0 && s[pos] > tmp) {
            // 后移一位留位置给待排元素
            s[pos + 1] = s[pos];
            pos--;
        }

        // 将待排序元素插入数组中
        s[pos + 1] = tmp;
    }
    return 0;
}

int main() {
    int a[10], i;
    printf("输入10个数：\n");
    for (i = 0; i < 10; i++) scanf("%d", &a[i]);

    insort(a, 10);

    printf("排序结果：\n");
    for (i = 0; i < 10; i++) printf("%5d", a[i]);
    printf("\n");

    return 0;
}