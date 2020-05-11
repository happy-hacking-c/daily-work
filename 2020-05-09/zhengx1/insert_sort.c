#include <stdio.h>

int main(int argc, char const *argv[])
{
	int arr[] = {1,9,2,5,22,1,23,344,556,11,28,5,41};
	int length = 13;

	for (int i = 1; i < length; ++i)
	{
		int insertValue = arr[i];
		int j = i-1;
		for (; (j >= 0) && (insertValue < arr[j]); --j)
		{

			arr[j+1] = arr[j];
		}
		arr[j+1] = insertValue;
	}

	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", arr[i]);
		/* code */
	}

	int arr2[] = {1,9,2,5,22,1,23,344,556,11,28,5,41};

	for (int i = 0; i < length-1; ++i)
	{
		int minIndex = i;
		for (int j = i+1; j < length; ++j)
		{
			minIndex = arr2[j] < arr2[minIndex] ? j : minIndex;

		}
		int tmp = arr2[minIndex];
		arr2[minIndex] = arr2[i];
		arr2[i] = tmp;

	}


	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", arr2[i]);
		/* code */
	}

	return 0;
}

