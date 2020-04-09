#include <stdio.h>
#include <string.h>

int Any(char src[],char sub[] ){
	if (strlen(src) == 0 || strlen(sub) == 0){
		return -1;
	}

	int i=0,j=0;
	while(src[i] != '\0'){
		printf("2222");	
		while(sub[j] != '\0'){
			if (src[i] == sub[j]){
				return i;
			}
			j++;
		}
		j=0;
		i++;
	}
	return -1;
}

int main(int argc,char *argv[]){
	
	char *str1 = "asdf";
	char *str2 = "df";
	int index = Any(str1,str2);
	printf("############");
	printf("index:%d\n",index);
	return 0;
}
