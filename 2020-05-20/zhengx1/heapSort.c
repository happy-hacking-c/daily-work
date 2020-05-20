#include <stdio.h>


void downAdjust(int array[],int parentIndex,int length)
{
	int temp = array[parentIndex];
	int childIndex = 2 * parentIndex +1;
	while(childIndex<length){
		if (childIndex +1 < length && array[childIndex+1] > array[childIndex])
		{
			childIndex ++;
		}
		if (temp >= array[childIndex])
		{
			/* code */
			break;
		}
		array[parentIndex] = array[childIndex];
		parentIndex = childIndex;
		childIndex = 2 * childIndex +1;
	}
	array[parentIndex] = temp;
}

void heapSort(int array[],int length){
	for (int i = (length-2)/2; i>= 0; i--)
	{
		downAdjust(array,i,length);
	}
	for (int i = length-1; i >0; i--)
	{
		int temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		downAdjust(array,0,i);
	}
}

int main(int argc, char const *argv[])
{
	int array[] = {9,7,3,5,1,2,6,8,4};
	/* code */
	int length = sizeof(array)/sizeof(int);
	heapSort(array,length);
	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", array[i]);
	}

	return 0;
}