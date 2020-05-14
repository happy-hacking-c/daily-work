#include <stdio.h>

void mergeSort(int arr[], int begin, int end);
void merge(int arr[], int begin, int mid, int end);
void printArr(int arr[],int size);

int main()
{
    int arr[16] = {3, 4, 5, 6, 7, 21, 34, 352, 1, 2, 3, 444, 5, 2, 555, 2};
    mergeSort(arr, 0, 16 - 1);
    printArr(arr,16);
    return 0;
}

void printArr(int arr[],int size){
    for (size_t i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);

    }
        printf("\n");

}

void merge(int arr[], int begin, int mid, int end)
{
    int begin1 = begin;
    int end1 = mid;
    int begin2 = mid + 1;
    int end2 = end;
    int index = begin;
    int size = end - begin + 1;
    int tmp[size];
    int i = 0;
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (arr[begin1] <= arr[begin2])
        {
            tmp[i++] = arr[begin1++];
        }
        else
        {
            tmp[i++] = arr[begin2++];
        }
    }

    while (begin1 <= end1)
    {
        tmp[i++] = arr[begin1++];
    }

    while (begin2 <= end2)
    {
        tmp[i++] = arr[begin2++];
    }

    for (int j = 0; j < size; j++){
        // printf("%d \n", tmp[j]);
        arr[begin + j] = tmp[j];
    }
    printArr(tmp,size);
    printArr(arr,16);
    return;
}

void mergeSort(int arr[], int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
    return;
}