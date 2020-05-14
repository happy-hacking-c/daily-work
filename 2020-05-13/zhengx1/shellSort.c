#include <stdio.h>

int main(int argc, char const *argv[])
{
	int array[] = {1,5,6,7,5,2,3,4,52,453,12,9,1,2,3};
    int	count = sizeof(array)/sizeof(int);
    int temp;
	/* code */
	for (int d = count/2; d > 0; d /=2)
	{
		for(int i=d;i<count;i=i+d) {
			                
			for(int j=i-d;j>=0&&array[j]>array[j+d];j=j-d) {

				temp = array[j+d];
                array[j+d]=array[j];
                array[j] = temp;

            }

        }
		/* code */
	}


	for (int i = 0; i < count; ++i)
	{
		printf("%d\n", *(array+i));
	}
	
	return 0;
}