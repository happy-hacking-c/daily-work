#include <stdio.h>
#define SIZE 16

void heapSort(int arr[], int lenth);
void buildHeap(int arr[], int lenth);
void downAdjust(int arr[], int parentIndex, int length);

int main()
{
    int array[SIZE] = {9, 3, 1, 4, 242, 12323, 1232, 445, 2, 22, 33, 4, 2, 344, 22, 3123};

    heapSort(array, SIZE);

    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%d \n", array[i]);
    }
    return 0;
}

void heapSort(int arr[], int length)
{
    buildHeap(arr, length);

    for (int i = length - 1; i > 0; i--)
    {
        int tmp = arr[i];
        arr[i] = arr[0];
        arr[0] = tmp;
        downAdjust(arr, 0, i);
    }
}

void buildHeap(int arr[], int lenth)
{
    for (int i = (lenth - 2) / 2; i >= 0; i--)
    {
        downAdjust(arr, i, lenth);
    }
}

//下沉
void downAdjust(int arr[], int parentIndex, int length)
{
    int tmp = arr[parentIndex];

    int childIndex = 2 * parentIndex + 1;
    while (childIndex < length)
    {
        if (childIndex + 1 < length && arr[childIndex + 1] > arr[childIndex])
        {
            childIndex++;
        }
        if (tmp >= arr[childIndex])
        {
            break;
        }
        arr[parentIndex] = arr[childIndex];
        parentIndex = childIndex;
        childIndex = 2 * childIndex + 1;
    }
    arr[parentIndex] = tmp;
}
