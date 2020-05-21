/**
 * 插入排序算法（double版）
 * 郑凯
 * 2020年5月21日
 * */

void insertSort(double *p, int len)
{

    //开始的时候将第二个元素拿出来，作为第一个比较元素
    for(int i = 1; i < len ; i++) {
        double tmp = *(p+i);
        int k = i - 1;
        //和左边第一个元素比，知道找到比他小的元素
        while(k >= 0 && *(p+k) > tmp)
            k--;

        //往后挪动中间比他大的元素，最终腾出来k+1位置，把tmp元素插进去
        for(int j = i; j > k + 1; j--)
           *(p+j) = *(p+j-1);

        //插到坑里
        *(p+k+1) = tmp;
    }

}
