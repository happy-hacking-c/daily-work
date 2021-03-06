//

#include "stdio.h"

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
    printf("%d\n", day_of_year(2020, 4, 22));

    int *pmonth, *pday;
    month_day(2020, 250, pmonth, pday);
    printf("%d-%d\n", *pmonth, *pday);

    return 0;
}

int day_of_year(int year, int month, int day) {
    if (month > 12 || month < 1 || day > 31 || day < 1) {
        return 0;
    }
    
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; i < month; i++) day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap, max;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    max = leap ? 366 : 365;
    if (year > max || year < 0) {
        return;
    }
    
    for (i = 1; yearday > daytab[leap][i]; i++) yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}