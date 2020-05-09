#include <stdio.h>

int main(int argc, char const *argv[])
{
	int arr[13] = {1,9,2,5,22,1,23,344,556,11,28,5,41};

	for (int i = 1; i < 13; ++i)
	{
		int insertValue = arr[i];
		int j = i-1;
		for (; (j >= 0) && (insertValue < arr[j]); --j)
		{

			arr[j+1] = arr[j];
		}
		arr[j+1] = insertValue;
	}

	for (int i = 0; i < 13; ++i)
	{
		printf("%d\n", arr[i]);
		/* code */
	}
	return 0;
}

