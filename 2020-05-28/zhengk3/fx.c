
/**
 * 清华大学“C语言程序设计”期末试卷题目2
 * 考点：递归函数
 * 郑凯
 * 2020年5月28日
 * */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define VALUE_MIN 0
#define VALUE_MAX 100

double myFunction(double x, double y);

double myFunction(double x, double y)
{
    //计算结果
    double fx;

    if( x == y ) {
        fx = x;
    }else if ( x < 1 || y < 1) {
        fx = 0;
    }else if ( x > y && y >= 1) {
        fx = myFunction(0.7 * x - 3, y) + myFunction(x, y - 8.4) + x + y + 1; 
    }else if ( y > x && x >= 1) {
        fx = myFunction(x / 2, y - 1) + myFunction(x - 1, y /3) + x + y;
    }

    return fx;
}


int main(int argc, char *argv[])
{
    int fd;

    if (argc < 3)
    {
        printf("Error: atleast tow number!\n");
    } else {
        double a , b;
        a = atof(*++argv);
        b = atof(*++argv);

        //怎么加校验输入的小数位小于等于4位？

        //判断取值范围
        if(a <= 0 || a >=100 || b <= 0 || b >=100) {
            printf("Error: number must greater than 0 and less than 100!\n");
        }else {
            printf("F(%.4lf,%.4lf) = %.2lf \n", a, b, myFunction(a, b));
        }

    }
        

    return 0;
}