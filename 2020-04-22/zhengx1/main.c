#include <stdio.h>

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year,int month, int day)
{
    int leap;
    leap = year %4 == 0 && year %100 !=0 || year %400 ==0;
    if(month < 1 || month > 12)
        return -1;
    if(day < 1 || day > daytab[leap][month])
        return -1;

    for (int j = 0; j < month; ++j) {
        day += daytab[leap][j];
    }
    return day;
}

void month_day(int year,int yearday, int *pmonth, int *pday)
{
    int j, leap;
    if(year < 1){
        *pmonth = -1;
        *pday = -1;
        return;
    }
    leap = year %4 == 0 && year %100 !=0 || year %400 ==0;
    if (leap == 1 && yearday > 366 || leap == 0 && yearday > 365){
        *pmonth = -1;
        *pday = -1;
        return;
    }

    for (j = 0; yearday>daytab[leap][j]; ++j) {
        yearday -= daytab[leap][j];

    }
    *pmonth = j;
    *pday = yearday;
}

int main() {
    int day = day_of_year(2020,4,22);
    printf("是第%d天!!\n",day);
    int pmonth,pday;
    month_day(2001,365,&pmonth,&pday);
    printf("是%d月%d号",pmonth,pday);

    return 0;
}
