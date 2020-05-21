#include <stdio.h>
#define SIZE 16
int partition(int arr[], int left, int right);
void quickSort(int arr[], int left, int right);



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