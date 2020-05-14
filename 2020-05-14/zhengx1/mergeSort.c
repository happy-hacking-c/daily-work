#include <stdio.h>

void mergeSort(int [],int,int);
void merge(int [],int,int,int);

int main(int argc, char const *argv[])
{
	int array[] = {5,8,6,3,9,2,1,7};
	int count = 8;
	mergeSort(array,0,count -1);
	for (int i = 0; i < count; ++i)
	{
		printf("%d\n", array[i]);
		/* code */
	}
	/* code */
	return 0;
}

void mergeSort(int array[],int start,int end)
{
	if (start<end)
	{
		int mid = (start+end)/2;
		mergeSort(array,start,mid);
		mergeSort(array,mid+1,end);
		merge(array,start,mid,end);
		/* code */
	}
}

void merge(int array[],int start,int mid,int end)
{
	int tempArray[end-start+1];
	int p1 = start;
	int p2 = mid +1;
	int p = 0;
	while (p1 <= mid && p2<= end){
		if(array[p1]<= array[p2])
			tempArray[p++] = array[p1++];
		else
			tempArray[p++] = array[p2++];
	}
	while(p1<=mid)
		tempArray[p++] = array[p1++];
	while(p2<=end)
		tempArray[p++] = array[p2++];
	for (int i = 0; i < end-start+1; ++i)
	{
		/* code */
		array[i+start] = tempArray[i];
	}
}