#include <stdio.h>

//函数实现
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    // int i = 0;
    while (low < high) {     
    	// printf("%d,%d,%d\n", low,mid,high);
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1 ;

        // i++;
        // if (i>10 )
        // {
        // 	break;
        // 	/* code */
        // }
    }
    return (x == v[low]) ? low : -1;}



int main(int argc, char const *argv[])
{
	/* code */

	int stack[] = {1,3,5,7,9,11};
	int needle = 9;
	printf("%d\n", binsearch(3,stack,6));

	return 0;
}



