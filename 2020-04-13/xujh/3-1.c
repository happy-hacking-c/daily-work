//
// Created by junhai on 2020/4/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <sys/time.h>
#include <sys/unistd.h>
#include <x86intrin.h>

static uint64_t rdtsc(){
    return __rdtsc();
}
static int binarySearch(short v[],int x,int n) {
    int low ,high, mid;
    low = 0;
    high = n-1;
    while(low <= high) {
        mid = low+(high-low>>1); //防止溢出风险？？
        if(x < v[mid]) {
            high = mid -1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

static int binarySearch2(short v[], int x, int n) {
    short low ,high, mid;
    low = 0;
    high = n-1;
    while(low <= high && x != v[mid=(low+high)/2]) {
        if(x < v[mid])
            high = mid -1;
        else
            low = mid + 1;
    }
    return  (x == v[mid]) ? mid : -1;
}

#include <unistd.h>
static double getCpuFre2(){
    int64_t tsc_start, tsc_end;
    struct timeval tv_start, tv_end;
    int usec_delay;

    tsc_start = rdtsc();
    gettimeofday(&tv_start, NULL);
    usleep(100000);
    tsc_end = rdtsc();
    gettimeofday(&tv_end, NULL);

    usec_delay = 1000000 * (tv_end.tv_sec - tv_start.tv_sec)
                 + (tv_end.tv_usec - tv_start.tv_usec);

    double fre = (double)(tsc_end-tsc_start) / usec_delay;
    printf("cpu MHz\t\t: %.3f\n",fre);
    return fre;
}

static double getCpuFre(){
    FILE *fp;
    char str[81];
    memset(str,0,81);
    fp=popen("cat /proc/cpuinfo|grep cpu\\ MHz|sed -e 's/.*:[^0-9]//'","r");
    if(fp<0){
        printf("无法读取CPU主频信息\n");
        return 0;
    }
    fgets(str,80,fp);
    fclose(fp);
    double spd=atof(str);
    printf("您CPU的主频是%fMHz\n",spd);
    return spd;
}

void testBinarySearch(){
    short a[SHRT_MAX];
    for(int i = 0 ; i < SHRT_MAX; i++) {
        a[i] = i;
    }
    printf("size of int: %d,max:%d\n", sizeof(short),SHRT_MAX);

    time_t start,stop;
    start = time(NULL);
    int idx = binarySearch2(a,2,SHRT_MAX);
    printf("binarySearch idx: %d\n",idx);
    stop = time(NULL);
    printf("Use Time:%ld\n",(stop-start)); //算不出来 = 0


    clock_t cstart,cend;
    double dur;
    cstart = clock();
    binarySearch2(a,2,SHRT_MAX);
    cend = clock();
    dur = (double)(cend - cstart);
    printf("Use Time:%f\n",(dur/CLOCKS_PER_SEC));

    struct timeval t1,t2;
    double timeuse;
    gettimeofday(&t1,NULL);
    binarySearch2(a,2,SHRT_MAX);
    gettimeofday(&t2,NULL);
    timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
    printf("Use Time:%f\n",timeuse);


    uint64_t tt1,tt2;
    tt1 = rdtsc();
    binarySearch2(a,2,SHRT_MAX);
    tt2 = rdtsc();
    printf("Use Time:%f\n",(tt2 - tt1)*1.0/(getCpuFre2()*1000)); //FREQUENCY  CPU的频率

    getCpuFre2();
    printf("您CPU的主频是%fMHz\n",getCpuFre());
}
