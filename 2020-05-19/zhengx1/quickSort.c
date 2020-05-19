#include <stdio.h>


int partition(int arr[],int startIndex,int endIndex)
{
	int pivot = arr[startIndex];
	int left = startIndex;
	int right = endIndex;
	int index = startIndex;

	while(right >= left){
		while(right>= left){
			if (arr[right]<pivot)
			{
				arr[left] = arr[right];
				index = right;
				left++;
				break;
			}
			right--;
		}
		while(right >= left){
			if (arr[left] > pivot)
			{
				arr[right] = arr[left];
				index = left;
				right--;
				break;
			}
			left++;
		}
	}
	arr[index] = pivot;
	return index;
}


void quickSort(int arr[],int startIndex,int endIndex)
{
	if (startIndex >= endIndex)
	{	
		return;
	}
	int pivotIndex = partition(arr,startIndex,endIndex);
	quickSort(arr,startIndex,pivotIndex-1);
	quickSort(arr,pivotIndex+1,endIndex);
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,3,9,5,7,45,56,10,1,9,13,2,4,4,56};
	quickSort(arr,0,sizeof(arr)/sizeof(int));
	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}


