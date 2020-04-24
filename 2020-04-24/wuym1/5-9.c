#include "stdio.h"

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
    printf("%d\n", day_of_year(2020, 4, 22));

    int pmonth, pday;
    month_day(2020, 61, &pmonth, &pday);
    printf("%d-%d\n", pmonth, pday);

    return 0;
}

int day_of_year(int year, int month, int day) {
    char *p;
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    p = &daytab[leap][1];
    for (i = 1; i < month; i++) {
        day += *p++;
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    char *p;
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    p = &daytab[leap][1];
    for (i = 1; yearday > *p; i++) {
        yearday -= *(p++);
    }
    *pmonth = i;
    *pday = yearday;
}