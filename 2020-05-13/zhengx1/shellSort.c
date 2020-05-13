#include <stdio.h>

int main(int argc, char const *argv[])
{
	int array[] = {1,5,6,7,5,2,3,4,52,453,12,9,1,2,3};
    int	count = sizeof(array)/sizeof(int);
	/* code */
	int d = count;
	while(d>1){
		d = d/2;
		for (int x = 0; x < d; ++x)
		{
			for(int i=x+d;i<count;i=i+d) {
				                
				int temp=array[i];
				int j;

                
				for(j=i-d;j>=0&&array[j]>temp;j=j-d) {

                    array[j+d]=array[j];

                }

                array[j+d]=temp;

            }
			/* code */
		}
	}

	for (int i = 0; i < count; ++i)
	{
		printf("%d\n", *(array+i));
	}
	
	return 0;
}