#include<stdio.h>
void swap(int *x, int *y);
void SelectSortOP(int *array, int size);

int main(){
    int arr[16] = {3,4,5,6,7,21,34,352,1,2,3,444,5,2,555,2};
    SelectSortOP(arr,16);
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

//选择排序的优化(一次将两个元素放在它的最终位置上）
void SelectSortOP(int *array, int size)
{
	//最小值下标
	int minpos = 0;
	//最大值下标
	int maxpos = 0;
	int left = 0;
	int right = size - 1;
	int j = 0;
	//循环size-1次
	while (left < right)
	{
		maxpos = left;
		minpos = left;
		//确定最大值下标以及最小值下标
		for (j = left; j <= right; j++)
		{
			if (array[j]>array[maxpos])
			{
				maxpos = j;
			}
			if (array[j] < array[minpos])
			{
				minpos = j;
			}
		}
		//将最大值插到最后
		if (maxpos != right)
		{
			swap(&array[maxpos], &array[right]);
		}
		//防止minpos在最大值要插入的位置
		if (minpos == right)
		{
			minpos = maxpos;
		}
		//将最小值插到最前面
		if (minpos != left)
		{
			swap(&array[minpos], &array[left]);
		}
		left++;
		right--;
	}
}