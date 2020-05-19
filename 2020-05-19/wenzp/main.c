#include <stdio.h>

void quickSort(int arr[], int low, int high)
{
    int first = low;
    int last  = high;
    int key = arr[first];
    if(low >= high)
        return;
    while(first < last)
    {
        while(first < last && arr[last] > key)
        {
            last--;
        }
        arr[first] = arr[last];

        while(first < last && arr[first] < key)
        {
            first++;
        }
        arr[last] = arr[first];
    }
    arr[first] = key;

    quickSort(arr, low, first-1);
    quickSort(arr, first+1, high);
}

int main()
{
    int i;
    int a[10] = {3, 1, 11, 5, 8, 2, 0, 9, 13, 81};

    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");

    quickSort(a, 0, 9);

    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}


