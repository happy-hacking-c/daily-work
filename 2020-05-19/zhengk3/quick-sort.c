
/**
 * 第31堂课作业：实现快速排序算法
 * 郑凯
 * 2020年5月19日
 * */
#include<stdio.h>

void quickSort(char *p, int start, int end);
int partition(char *p, int start, int end);
void myPrint(char *p);

int partition(char *p, int start, int end)
{
    //取第一个位置的元素作为基准元素
    int pivot = *(p+start);
    int left = start;
    int right = end;

    while (left != right)
    {

        //控制right指针比较并左移
        while (left < right && *(p+right) > pivot)
        {
            right--;
        }

        //控制right指针比较并右移
        while (left < right && *(p+left) <= pivot)
        {
            left++;
        }

        //交换left和right指向的元素
        if (left < right)
        {

            int tmp = *(p+left);
            *(p+left) = *(p+right);
            *(p+right) = tmp;
        }
    }

    //pivot和指针重合点交换
    int temp = *(p+left);
    *(p+left) = *(p+start);
    *(p+start) = temp;

    return left;
}

void quickSort(char *p, int start, int end)
{

    //结束递归
    if (start < end) {

        //基准元素位置
        int pivotIndex = partition(p, start, end);
        //左
        quickSort(p, start, pivotIndex - 1);
        //右
        quickSort(p, pivotIndex + 1, end);

    }

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

    printf("Before:\n");
    myPrint(myArray);

    quickSort(myArray, 0 , 11);

    printf("After:\n");
    myPrint(myArray);

    return 0;
}