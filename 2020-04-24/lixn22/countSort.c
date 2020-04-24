#include <stdio.h>
#include <malloc.h>
#include <string.h>

void CountSort(int *arr, int size)
{
    int i;
    int minValue = arr[0];
    int maxValue = arr[0];
    int range = 0;
    int *tmp = 0;
    int count = 0;
    for (i = 0; i < size; i++)//计算数据的分散空间
    {
        if (arr[i] < minValue){
            minValue = arr[i];
        }
        if (arr[i] > maxValue){
            maxValue = arr[i];
        }
    }
    range = maxValue - minValue + 1;
    tmp = (int*)malloc(sizeof(arr[0])*size);//申请辅助空间
    if (tmp == NULL)
        return;
    memset(tmp, 0, sizeof(int)*range);//初始化

    for (i = 0; i < size; i++)//统计每个元素出现的次数
    {
        tmp[arr[i] - minValue]++; // 不能直接使用arr[i] 作为下标，非php
    }

    for(i=0;i<range;i++)//通过统计tmp[];回收元素
    {
        while (tmp[i]--)
        {
            arr[count++] = i + minValue;
        }
    }
    free(tmp);
}

void printf_arr(int arr[],int size) //打印数组
{
    int i = 0;
    for (; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}



int main()
{
    //int arr[10] = {2,7,1,4,3,9,6,0,5,8};
    int arr[10] = { 4,4,6,7,3,0,9,3,5,2 };
    int size = sizeof(arr) / sizeof(arr[0]);

    CountSort(arr, size);
    printf_arr(arr, size);
    return 0;
}
