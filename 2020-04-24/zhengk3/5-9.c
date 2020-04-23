
/**
 * 第15堂课作业：5-9
 * 数组下标操作方式改为指针
 * 郑凯
 * 2020年4月22日
 * */
#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};


int day_of_year(int year, int month, int day)
{
    char *p;
    int leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];
    while(--month)
        day += *++p;
    
    return day;
}
/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    char *p;
    int leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];
    while(yearday > *++p)
        yearday -= *p;
    //指针移动的距离，p是移动之后的位置，*（daytab+leap）是之前的位置
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}

int main()
{
    printf("%d\n", day_of_year(2020,4,22));

    int month, day;

    month_day(2020,113,&month,&day);
    printf("2020-%d-%d\n",month, day);
    return 0;
}