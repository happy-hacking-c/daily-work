#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int validateYear(int year) {
    if (year > 0) {
        return 1;
    }
    return 0;
}

int isleap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int validateMonth(int month) {
    if (month >= 1 && month <= 12) {
        return 1;
    }
    return 0;
}



int validateDay(int year, int month, int day) {
    int leap;
    leap = isleap(year);

    if (day > 0 && day <= daytab[leap][month]) {
        return 1;
    } 
    return 0;
}

int validateDays(int year, int yearday) {
    int leap, days;
    leap = isleap(year);
    int i = 1;
    days = 0;
    while(i <= 12) {
        days += daytab[leap][i];
        i++;
    }

    if (yearday > 0 && yearday <= days) {
        return 1;
    }

    return 0;
}
/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = isleap(year);
    char *p = &daytab[leap][0];
    if (validateMonth(month) && validateYear(year) && validateDay(year, month, day)) {
        for (i = 1; i < month; i++)
            day += *++p;
        return day;
    }
    return -1;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = isleap(year);
    char *p = &daytab[leap][0];
    if (validateYear(year) && validateDays(year, yearday)) {
        for (i = 1; yearday > daytab[leap][i]; i++)
            yearday -= *++p;
        *pmonth = i;
        *pday = yearday;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int pm, pd;
    printf("%d", day_of_year(2020, 2, 29));
    
    month_day(2020, 366, &pm, &pd);
    printf("%d,%d", pm, pd);
    return 0;
}
