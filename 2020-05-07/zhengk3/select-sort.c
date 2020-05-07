
/**
 * 第22堂课作业：用C语言实现选择排序算法
 * 郑凯
 * 2020年5月6日
 * */
#include <stdio.h>

void selectSort(char *p);
void myPrint(char *p);

void selectSort(char *p)
{
    int len = 0;
    char *t = p;
    while(*t++ != '\0')
        len++;

    for(int i = 0; i < len -1 ; i++) {
        int min = i;

        for(int j = i + 1; j < len; j++) {

            if(*(p+min) > *(p+j)) 
               min = j;

        }

        int tmp = *(p+i);
        *(p+i) = *(p+min);
        *(p+min) = tmp;
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

    selectSort(myArray);

    myPrint(myArray);

    return 0;
}