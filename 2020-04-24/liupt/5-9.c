#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int year = 1999;
    int month = 9;
    int day = 24;
    int days = 0;
    int monthpter ,daypter;

    days = day_of_year(year, month, day);
    printf("day_of_year date:%d-%d \n", year, days);
    month_day(year, days, &monthpter, &daypter);
    printf("month_day date:%d-%d-%d \n", year, monthpter, daypter);
    return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    char * daytabitem = daytab[leap];
    while(month-- > 0){
        day += *daytabitem++;
    }
    return day;
}
/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    char * daytabitem = daytab[leap];
    *pmonth = 0;
    while (yearday > *daytabitem)
    {
        yearday -= *daytabitem++;
        (*pmonth)++;
    }
    *pday = yearday;
}