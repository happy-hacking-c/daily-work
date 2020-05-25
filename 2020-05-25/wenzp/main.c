#include <stdio.h>
#include <ctype.h>
#include <string.h>
int my_isupper1(int c){
    return (c>='A'&&c<='Z');
}
int my_isupper2(int c){
    return (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ",c)!=NULL);
}

int main(int argc,char *argv[]){

	printf("a1:%d\n",my_isupper1('A'));
	printf("a1:%d\n",my_isupper1('a'));
	printf("a2:%d\n",my_isupper2('A'));
	printf("a2:%d\n",my_isupper2('a'));
	return 0;
}
