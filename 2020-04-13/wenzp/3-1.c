#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
   
	 while (low <= high) {
        mid = (low+high)/2;
		printf("v[mid]:%d\n",v[mid]);
        if (x < v[mid])
           high = mid - 1;
        else if (x  > v[mid])
           low = mid + 1;
        else    /* found match */
	   	   return mid;
	}

    return -1;   /* no match */
}

int main(int argc,char *argv[]){
	int arrSrc[] = {1,2,3,4,20,21,32,41,67};
	printf("len:%lu\n",sizeof(arrSrc)/sizeof(int));
	printf("res:%d\n",binsearch(21,arrSrc,9));
	return 0;
}
