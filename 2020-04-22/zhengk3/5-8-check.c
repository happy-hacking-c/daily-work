
/**
 * 第13堂课作业：5-8
 * 对示例代码进行错误检查
 * 郑凯
 * 2020年4月22日
 * */
#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day)
{
    int days;
    //检查年月日
    if(year >= 0 && month >=1 && month <= 12 && day >0){
        int i, leap;
        leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

        //每个月的天数是否正确
        if(day <= daytab[leap][month]) {
            for (i = 1; i < month; i++)
                day += daytab[leap][i];
                days = day;
        }
        
    }
    
    return days;
}
/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int result;
    //检查年月日
    if(year >= 0 && yearday >0){
        int i, leap;
        leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
        //平年闰年总天数检查
        if((leap == 1 && yearday <= 366) || (leap == 0 && yearday <= 365)){
            for (i = 1; yearday > daytab[leap][i]; i++)
                yearday -= daytab[leap][i];
                *pmonth = i;
                *pday = yearday;
                result = 1;
        }
        
    }

    return result;
    
}

int main()
{
    int days;
    days = day_of_year(2020,4,42);

    if(days){
        printf("%d\n", days);
    }else{
        printf("input date is error\n");
    }
    

    int month, day;
    int year = 2019, yearday = 366;

    if(!month_day(year,yearday,&month,&day)) {
        printf("input year or yearday error\n");
    }else{
        printf("%d-%d-%d\n",year, month, day);
    }
    
    return 0;
}