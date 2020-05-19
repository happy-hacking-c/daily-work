#include <stdio.h>
#define SIZE 16
int partition(int arr[], int left, int right);
void quickSort(int arr[], int left, int right);

int main()
{
    int arr[SIZE] = {9, 3, 1, 4, 242, 12323, 1232, 445, 2, 22, 33, 4, 2, 344, 22, 3123};
    quickSort(arr, 0, SIZE-1);
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%d \n", arr[i]);
    }
    return 0;
}


void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int i = left;
    int j = right;
    while (i < j)
    {
        while (i < j && arr[j] >= pivot)
        {
            j--;
        }
        while (i < j && arr[i] <= pivot)
        {
            i++;
        }

        if(i < j){
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    arr[left] = arr[i];
    arr[i] = pivot;
    return i;
}