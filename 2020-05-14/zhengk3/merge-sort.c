
/**
 * 第28堂课作业：用C语言实现归并排序算法
 * 郑凯
 * 2020年5月14日
 * */
#include <stdio.h>

void mergeSort(char *p, int start, int end);
void merge(char *p, int start, int mid, int end);
void myPrint(char *p);

void mergeSort(char *p, int start, int end)
{
    if(start < end) {
        //折半成两个小集合，分别进行递归
        int mid = (start + end) /2;
        mergeSort(p, start, mid);
        mergeSort(p, mid+1, end);
        //把两个有序小集合，归并成一个大集合
        merge(p, start, mid, end);
    }

}


void merge(char *p, int start, int mid, int end)
{
    
    //开辟额外大集合，设置指针
    int temp[end - start + 1];
    int p1 = start , p2 = mid+1, q=0;

    //比较两个小集合的元素，依次放入大集合
    while (p1 <= mid && p2 <= end)
    {
        if(*(p+p1) <= *(p+p2)) {
            temp[q++] = *(p+(p1++));
        }else{
            temp[q++] = *(p+(p2++));
        }
    }

    //左侧小集合还有剩余，依次放入大集合尾部
    while (p1 <=mid)
        temp[q++] = *(p+(p1++));

    //右侧小集合还有剩余，依次放入大集合尾部
    while (p2 <=end)
        temp[q++] = *(p+(p2++));

    //把大集合的元素复制回原数组
    for(int i=0; i < (end - start + 1); i++)
       *(p+i+start) = temp[i];

}

void myPrint(char *p)
{
    while (*p != '\0')
        printf("%d ", *p++);
    
    printf("\n");
    
}


int main()
{
    char myArray[13] = {1,52,23,16,95,40,32,15,87,82,6,15};

    mergeSort(myArray, 0, 11);

    myPrint(myArray);

    return 0;
}