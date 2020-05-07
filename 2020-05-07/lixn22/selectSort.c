#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
 
#define MAX_SIZE 101
#define SWAP(x, y, t)  (t = x, x = y, y = t)
 
void sort(int[], int);      /* selection sort */
 
int main(void)
{
    int i, n;
    int list[MAX_SIZE];
    printf("Enter the number of numbers to generate: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_SIZE){
        fprintf(stderr, "Improper value of n\n");
        return 0;
    }
    srand((unsigned)time(0));
    for (i = 0; i < n; i++){    /* randomly generate numbers */
        list[i] = rand();
        printf("%d ", list[i]);
    }
    sort(list, n);
    printf("\n Sorted array:\n");
    for (i = 0; i < n; i++)    /* print out sorted numbers */
        printf("%d ", list[i]);
    printf("\n");
}
 
 
void sort(int list[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n; i++){
        min = i;
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[min])
                min = j;
        }
        SWAP(list[i], list[min], temp);
    }
}
