#include <stdio.h>
#include <sys/time.h>
#include <sys/unistd.h>

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0; // 第0个索引
    high = n - 1; // 最后一个索引
    usleep(10000);
    while (low <= high)
    {
        mid = (low + high)/2;
        if (x < v[mid])
        {
            high = mid + 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int binsearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0; // 第0个索引
    high = n - 1; // 最后一个索引
    mid = (low + high)/2;
    usleep(10000);
    while (x != v[mid] && low <= high)
    {
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

        mid = (low + high)/2;
    }
    if (x == v[mid])
    {
        return mid;
    }
    else
    {
        return -1;
    }
    
    return -1;
}
int main() {
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    int pos, pos2;

    struct timeval start, end;
    gettimeofday(&start, NULL);
    pos = binsearch(7, v, 10);
    gettimeofday(&end, NULL);
    int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;

    printf("binsearch time use:%d\n", timeuse);
    printf("%d\n", pos);

    struct timeval start2, end2;
    gettimeofday(&start2, NULL);

    pos2 = binsearch2(7, v, 10);
    gettimeofday(&end2, NULL);
    int timeuse2 = 1000000 * ( end2.tv_sec - start2.tv_sec ) + end2.tv_usec - start2.tv_usec;

    printf("binsearch2 time use:%d\n", timeuse2);
    printf("%d", pos2);
    return 0;
}
