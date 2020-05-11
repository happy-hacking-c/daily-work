#include <stdio.h>

void bubbleSort(int a[], int n)
{
    int i, j, tmp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

int main(int argc, char **argv)
{
    int a[] = {5, 3, 2, 7, 0};
    size_t size = sizeof(a) / sizeof(a[0]);
    bubbleSort(a, size);
}
