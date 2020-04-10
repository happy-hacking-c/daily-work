#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void int_to_b(int input){
	int binary[32] = {0};
	int i = 0;
	int n = abs(input);

	while(n){
	
		if(n % 2 == 1){
			binary[i++] = 1;
		}else{
			binary[i++] = 0;
		}

		n /= 2;
	}

	if(input < 0)	binary[31] = 1;	
	
			else binary[31] = 0;

	for(int k = 31; k >= 0; k--){
			printf("%d",binary[k]);
	}
	printf("\n");

}
