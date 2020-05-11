#include <stdio.h>

int main(int argc, char const *argv[])
{
	int arr[] = {1,3,5,8,5,3,1,2,5,2};
	int count = 10;
	int x = 0;
	int lastIndex = 0;
	int sortBorder = count -1;
	for (int i = 0; i < count; ++i)
	{
		char isSort = 1;
		
		for (int j = 0; j < sortBorder; ++j)
		{
			x++;
			if (arr[j]>arr[j+1])
			{
				
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				isSort = 0;
				lastIndex = j;

			}
		}
		if (isSort)
		{
			break;
		}
		sortBorder = lastIndex;
	}

	for (int i = 0; i < count; ++i)
	{
		/* code */
		printf("%d\n", arr[i]);
	}
	printf("total %d\n", x);

	return 0;
}