
/**
 * 第5堂课作业：3-1
 * 郑凯
 * 2020年04月12日15:01:26
 * */

#include <stdio.h>
#include <time.h>
#include <limits.h>


//函数声明
int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

//函数实现
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
        
    }

    return -1;
}

int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while ( low <= high && x != v[mid] ) {
        if ( x < v[mid] )
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low+high) / 2;
    }

    //把计算和判断拿到while循环外面来
    if ( x == v[mid] )
        return mid;
    else
        return -1;
}


int main()
{
    int t = 25;
    int ts[] = {1,4,7,11,15,18,21,22,24,25,29,30,35,56,67,89,90,92,100,120};
    
    //程序计时
    clock_t start,finish;

    start = clock();
    binsearch(t, ts ,20);
    finish = clock();
    printf("binsearch runing time: %lu（%f s）\n", finish-start, (double)((finish-start)/CLOCKS_PER_SEC));
    
    start = clock();
    binsearch2(t, ts ,20);
    finish = clock();
    printf("binsearch2 runing time: %lu（%f s）\n", finish-start, (double)((finish-start)/CLK_TCK));

    //CLK_TCK被认为已过时，建议使用 CLOCKS_PER_SEC
    //更多细节https://ask.zkbhj.com/?/question/355
    
    return 0;
}
