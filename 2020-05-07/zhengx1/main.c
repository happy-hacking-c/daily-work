#include <stdio.h>


void selectionSort(int [],int n);

int main(int argc, char const *argv[])
{
    /* code */
    int arr[] = {1,3,4,4,5435,1,976};
    int len = sizeof arr / sizeof(int);
    selectionSort(arr,len);
    for (int i = 0; i < len; ++i)
    {
        /* code */
       printf("%d\n",arr[i]);
    }


    return 0;
}

void selectionSort(int arr[],int n) {
    int i,j;
    int temp;
    for (i = 0; i < n-1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}