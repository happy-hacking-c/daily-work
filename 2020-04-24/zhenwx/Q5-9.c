
#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day) {
    int leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    char *p;
    p = daytab[leap];

    while (--month) day += *++p;

    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    char *p;
    p = daytab[leap];
    int i =1;
    while (yearday > *++p) {
        i++;
        yearday -= *p;
    }

    *pmonth = i;
    *pday = yearday;
}

int main() {
    printf("%d\n", day_of_year(2020, 4, 22));

    int month, day;

    month_day(2000, 269, &month, &day);
    printf("2000-%d-%d\n", month, day);
    return 0;
}