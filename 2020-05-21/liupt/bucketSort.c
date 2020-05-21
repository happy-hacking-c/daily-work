#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quickSort.c"

extern void quickSort(int arr[], int left, int right);

struct barrel
{
    int node[10];
    int count;
};

void bucketSort(int data[], int size)
{
    int max, min, num, pos;
    int i, j, k;
    struct barrel *pBarrel;
    max = min = data[0];
    for (i = 0; i < size; i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
        else if (data[i] < min)
        {
            min = data[i];
        }
    }
    num = (max - min + 1) / 10 + 1;

    printf("num : %d \n", num);
    pBarrel = (struct barrel *)malloc(sizeof(struct barrel) * num);
    memset(pBarrel, 0, sizeof(struct barrel) * num);

    for (i = 0; i < size; i++)
    {
        k = (data[i] - min + 1) / 10;
        printf(" k : %d : ++ %d -- : %d \n", k,(pBarrel + k)->count,data[i]);

        (pBarrel + k)->node[(pBarrel + k)->count] = data[i];
        (pBarrel + k)->count++;
    }

    pos = 0;
    for (i = 0; i < num; i++)
    {
        quickSort((pBarrel + i)->node, 0, (pBarrel + i)->count-1);
        for (j = 0; j < (pBarrel + i)->count; j++)
        {
            data[pos++] = (pBarrel + i)->node[j];
            printf(" -- %d -- : j : %d : %d \n", i,j,(pBarrel + i)->node[j]);
        }
    }
    free(pBarrel);
}

int main()
{
    int data[] = {9, 3, 1, 4, 24, 2, 32, 47, 2, 22, 33, 4, 2, 23, 22, 32};
    int size = sizeof(data) / sizeof(int);
    bucketSort(data, size);
    for (size_t i = 0; i < size; i++)
    {
        printf("%zu : %d \n", i,data[i]);
    }
    return 0;
}
