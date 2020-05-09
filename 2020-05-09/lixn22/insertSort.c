#include <stdio.h>

void insertSort(int a[], int n)
{
    int i, j;
    for(i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            int temp=a[i];
            for(j=i-1;j>=0 && a[j]>temp;j--)
                a[j+1]=a[j];
            a[j+1]=temp;
        }
    }

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

int main(int argc, char **argv)
{
    int a[] = {5, 3, 2, 7, 0};
    size_t size = sizeof(a) / sizeof(a[0]);
    insertSort(a, size);
}
