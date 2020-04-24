#include <stdio.h>
#include <stdlib.h>
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int main(int argc, char *argv[]) {
	return 0;
}
static int dayab[2][13]={{0,31,30,31,30,31,30,31,31,30,31,30,31},{0,31,30,31,30,31,30,31,30,31,31,30,31,30,31}};
int day_of_year(int day,int month,int year,int *pday){
	int leap;
	int i;
	int yearday;
	leap=year%4==0&&year%100!=0||year%400==0;
	*pday=dayab[leap][1];
	for(;pday<dayab[leap][month];pday++){
		day+=*pday;
	}
	return day;
}
