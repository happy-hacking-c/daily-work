
/**
 * 第27堂课作业：用C语言实现希尔排序算法
 * 郑凯
 * 2020年5月13日
 * */
#include <stdio.h>

void shellSort(char *p);
void myPrint(char *p);

void shellSort(char *p)
{
    int len = 0;
    char *t = p;
    while(*t++ != '\0')
        len++;

    //采用希尔增量，折半
    int gap = len /2;
    //一直处理到最后一轮（全集的直接插入排序）
    while(gap > 1) {
        //每轮将增量进行折半
        gap = gap /2;
        //从左边第一个元素开始，知道本次折半的地方
        for(int x = 0;x < gap; x++) {
            //从折半初的第一个元素开始，
            for(int i = x + gap; i < len; i +=gap ){
                int tmp = *(p+i);
                int j;
                //在组内进行比较大小，如果左边的元素比右边的大，则进行交换
                for(j = i - gap; j >=0 && *(p+j) > tmp; j-=gap){
                    *(p+j+gap) = *(p+j);
                }
                *(p+j+gap) = tmp;
            }

        }
    }

}

void myPrint(char *p)
{
    while (*p != '\0')
        printf("%d ", *p++);
    
    printf("\n");
    
}


int main()
{
    char myArray[13] = {1,52,23,16,95,40,32,15,87,82,6,15};

    shellSort(myArray);

    myPrint(myArray);

    return 0;
}