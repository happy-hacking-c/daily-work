#include <stdio.h>
int row = 2;
int col = 13;

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
    if(day < 1 || day > *(*daytab+leap*col+month))
        return -1;

    for (int j = 0; j < month; ++j) {
        day += *(*daytab+leap*col+j);
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

    for (j = 0; yearday>*(*daytab+leap*col+j); ++j) {
        yearday -= *(*daytab+leap*col+j);

    }
    *pmonth = j;
    *pday = yearday;
}

int main() {q

    int a = 0;
    int b = 1;
    int c = 1;
    int d = a | b & c;
    printf("%d",d);

    int year = 2020;
    int month = 4;
    int day = 24;
    int dayth = 115;
    int pm,pd;

    month_day(year,dayth,&pm,&pd);
    printf("%d-%d-%d是第%d天\n",year,month,day,day_of_year(year,month,day));
    printf("%d年的第%d天是%d-%d\n",year,dayth,pm, pd);
    return 0;
}






