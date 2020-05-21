
/**
 * 第33堂课作业：实现桶排序算法
 * 郑凯
 * 2020年5月21日
 * */
#include<stdio.h>
#include "insert-sort-double.c"
#define COUNTS 12

void insertSort(double *p, int len);
void bucketSort(double *p, int len);
void myPrint(double *p, int len);

void bucketSort(double *p, int len)
{
    //得到待排序序列中的最大值和最小值
    double max = *p;
    double min = *p;

    for(int i = 0; i < len; i++) {
        if (*(p+i) > max)
        {
            max = *(p+i);
        }

        if (*(p+i) < min)
        {
            min = *(p+i);
        }
    }
    double d = max - min;

    //创建桶并初始化
    int bucketNum = len;
    double bucketList[len][len];
    for(int j = 0; j < bucketNum; j++) {
        bucketList[j][0] = 0;
    }

    //初始化一个临时变量，记录每个桶中的元素数
    int itemCounts[len];
    for(int t = 0; t < len; t++) {
        itemCounts[t] = 0;
    }

    //遍历原始数组，将每个元素放入桶中
    for(int x = 0; x < len; x++) {
        int index = (int)((*(p+x) - min) * (bucketNum -1) / d);
        printf("keyIndex:%d,\n",index);
        bucketList[index][itemCounts[index]] = *(p+x);
        itemCounts[index] += 1;
        printf("keyIndex counts:%d\n",itemCounts[index]);
    }

    //对每个内部桶进行排序
    for(int y = 0; y < bucketNum; y++) {
        //排序
        insertSort(bucketList[y], itemCounts[y]);
    }

    //按顺序输出
    int pIndex = 0;
    for(int i = 0; i < len; i++) {
        if(bucketList[i][0]) {
            for(int j = 0; j < itemCounts[i]; j++) {
                *(p+pIndex) = bucketList[i][j];
                pIndex++;
            }
        }
    }
}


void myPrint(double *p, int len)
{

    while (len-- > 0)
        printf("%f ", *p++);
    
    printf("\n");
    
}


int main()
{

    double myArray[COUNTS] = {1.5,5.32,2.63,1.36,9.85,4.48,8.9,7.12,8.57,9.82,6.21,11.35};

    printf("heapSort Before:\n");
    myPrint(myArray, COUNTS);

    bucketSort(myArray, COUNTS);

    printf("heapSort After:\n");
    myPrint(myArray, COUNTS);

    return 0;
}