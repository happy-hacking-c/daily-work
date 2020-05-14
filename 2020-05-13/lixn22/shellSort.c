#include <stdio.h>
#include <math.h>

void shellSort(int *arr, int length)
{
    int temp;
    int j;
    for (int d = (length / 3) + 1; d >= 1; d = d / 2)
    {
        for (int i = d; i < length; ++i)
        {
            temp = arr[i];
            for (j = i - d; j >= 0 && temp < arr[j]; j = j - d)
            {
                arr[j + d] = arr[j];
            }
            arr[j + d] = temp;
        }
    }
}

int main()
{
    int array[] = {5, 3, 2, 7, 0};
    size_t size = sizeof(array) / sizeof(array[0]);
    shellSort(array, size);
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    return 0;
}
