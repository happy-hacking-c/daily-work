#include <stdio.h>
int isLeapYear(int year)
{
return year%4==0&&year%100!=0||year%400==0;
}
int day_of_year(int year, int month, int day)
{
const int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int i,s=day;
for(i=0;i<month-1;i++)
s+=m[i];
if(isLeapYear(year))
s++;
return s;
}

int main(int argc,char *argv[]){
	printf("days:%d\n",day_of_year(2020,3,4));
return 0;
}
