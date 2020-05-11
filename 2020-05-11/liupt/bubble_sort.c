#include<stdio.h>
void swap(int *x, int *y);
void bubbleSort(int *array, int size);

int main(){
    int arr[16] = {3,4,5,6,7,21,34,352,1,2,3,444,5,2,555,2};
    bubbleSort(arr,16);
    for (size_t i = 0; i < 16; i++)
    {
        printf("%d \n",arr[i]);
    }
    
}

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


void bubbleSort(int *array, int size){
    for(int i=0;i<size;i++){
        for (size_t j = i+1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                swap(&array[i],&array[j]);
            }
        }
    }
}