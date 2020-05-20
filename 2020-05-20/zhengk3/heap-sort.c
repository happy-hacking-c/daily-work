
/**
 * 第32堂课作业：实现堆排序算法
 * 郑凯
 * 2020年5月20日
 * */
#include<stdio.h>

void heapSort(char *p);
void downAdjust(char *p, int parentIndex, int lenth);
void myPrint(char *p);

void downAdjust(char *p, int parentIndex, int lenth)
{
    //保存父节点
    int temp = *(p+parentIndex);
    int childIndex = 2 * parentIndex + 1;
    while(childIndex < lenth) {
        //如果有右孩子，且右孩子大于左孩子，则定位到右孩子
        if(childIndex + 1 < lenth && *(p + childIndex + 1) > *(p + childIndex)) {
            childIndex++;
        }

        //如果父节点小于任何一个孩子的值，直接跳出
        if(temp > *(p + childIndex))
           break;

        //单向赋值
        *(p + parentIndex) = *(p + childIndex);
        parentIndex = childIndex;
        childIndex = 2 * childIndex + 1;
    }

    *(p + parentIndex) = temp;

}

void heapSort(char *p)
{
    int len = 0;
    char *t = p;
    while(*t++ != '\0')
        len++;

    //将数组构建成二叉堆
    for(int i =(len - 2)/2; i >=0; i--){
        downAdjust(p, i, len);
    }

    //循环删除堆顶元素，移到集合尾部，调节堆产生新的对顶
    for(int i = len - 1; i >0; i--) {
        //最后一个元素和第一元素进行交换
        int tmp = *(p+i);
        *(p+i) = *p;
        *p = tmp;
        //下沉调整最大堆
        downAdjust(p,0,i);
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

    printf("heapSort Before:\n");
    myPrint(myArray);

    heapSort(myArray);

    printf("heapSort After:\n");
    myPrint(myArray);

    return 0;
}