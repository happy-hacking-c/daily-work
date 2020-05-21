#include <stdio.h>

int main() {
    int arr[10] = {95, 94,93,95,98,99,96,97,96,91};
    int max = arr[0];
    int min = arr[0];
    for(int i = 1;i<10;i++) {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    int bucketNum = max - min; // 桶個數
    int bucketArr[bucketNum][10]; // 桶數組
    int countSize[bucketNum];
    for(int i = 0; i< bucketNum;i++) {
        countSize[i] = 0;
    }
    //printf("%d, %d, %d\n", max, min, bucketNum);


    for(int i=0;i<10;i++) {
        int bucketIndex; // 當前元素所在桶

        bucketIndex = (int)(arr[i] - min) * (bucketNum - 1) / bucketNum;
        //printf("%d \n", bucketIndex);
        
        //printf("%d~", countSize[bucketIndex]);
        bucketArr[bucketIndex][countSize[bucketIndex]++] = arr[i];

        //*(bucketArr+bucketIndex)++ = arr[i];
        //countSize[bucketIndex]++;
    }

    for(int i = 0; i< bucketNum;i++) {
       for(int j = 0; j < countSize[i];j++) {
           printf("%d, ", bucketArr[i][j]);
       }
    }
    //printf("asdfaf");
    return 0;
}
