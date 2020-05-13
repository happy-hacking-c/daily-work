#include <stdio.h>
void InsertSort(int arr[], int start, int end);
void binary_insert_sort(int arr[], int len);
void shellsort(int A[], int l, int h);
void swap(int *a, int *b);

int main(){
    int arr[16] = {3,4,5,6,7,21,34,352,1,2,3,444,5,2,555,2};
    shellsort(arr,0,16);
    for (size_t i = 0; i < 16; i++)
    {
        printf("%d \n",arr[i]);
    }
}

// 插入排序

// 直接插入排序
// 时间复杂度为O（n^2）稳定的排序元素移动是顺序的
// 在一个数组中，将第一个元素看作排序元素序列里的唯一元素，然后用临时变量tmp首先存放第二元素,即可在数组中空第二个元素位置（即此位置可被覆盖），
// 将第二个元素与有序序列里面唯一一个元素进行比较，根据排序条件决定元素是否需要向后移动，然后有序序列元素加一，申请空间里面存放将要插进有序序列里面的元素；
void InsertSort(int arr[], int start, int end)
{
    int tmp = arr[start];
    for (int i = start + 1; i <= end; ++i)
    {
        tmp = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > tmp)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = tmp;
    }
}

// 优化一：折半插入排序（Binary Insertion Sort）是对插入排序算法的一种改进，
// 所谓排序算法过程，就是不断的依次将元素插入前面已排好序的序列中，在寻找插入点时采用了折半查找。
// 时间复杂度：O(n^2)，稳定性：稳定。

// 排序思想：有一组数据待排序，排序区间为Array[0]~Array[n-1]。
// 将数据分为有序数据和无序数据，第一次排序时默认Array[0]为有序数据，Array[1]~Array[n-1]为无序数据。
// 有序数据分区的第一个元素位置为low，最后一个元素的位置为high。

// 遍历无序区间的所有元素，每次取无序区间的第一个元素Array[i]，因为0~i-1是有序排列的，所以用中点m将其平分为两部分，
// 然后将待排序数据同中间位置为m的数据进行比较，若待排序数据较大，则low~m-1分区的数据都比待排序数据小，
// 反之，若待排序数据较小，则m+1~high分区的数据都比 待排序数据大，此时将low或high重新定义为新的合适分区的边界，
// 对新的小分区重复上面操作。直到low和high 的前后顺序改变，此时high+1所处位置为待排序数据的合适位置。

void binary_insert_sort(int arr[], int len)
{
    int i, j, temp, m, low, high;
    for (i = 1; i < len; i++)
    {
        temp = arr[i];
        low = 0;
        high = i - 1;
        while (low <= high)
        {
            m = (low + high) / 2;
            if (arr[m] > temp)
                high = m - 1;
            else
                low = m + 1;
        }
        for (j = i - 1; j >= high + 1; j--)
            arr[j + 1] = arr[j];
    }
    arr[j + 1] = temp;
}

// 优化二：希尔排序法是对直接插入排序法的优化，通过设置一个增量，对原始序列进行分组，对每组用直接插入排序法排序再整合，
// 再缩小增量，周而复始直至增量为1，完成排序，因此又叫“缩小增量排序法”。

// 其实到希尔算法进行到最后，n的值变为1（即增量或者称跳跃数变为1）的时候，它就是直接插入排序，
// 只不过这时候，整个序列基本上是有序的，需要交换的数据已经非常少了，提高效率。

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shellsort(int A[], int l, int h)
{
    if (l < h)
    {
        int d; //增量
        int tmp;
        int j;
        int size = h - l + 1;
        for (d = size / 2; d >= 1; d /= 2)
        {
            //组内使用插入排序
            //d+l是第1组的第2个元素
            for (int i = d + l; i <= h; i++)
            {
                tmp = A[i];
                j = i - d; //该组中，当前元素的前一个元素
                //寻找要插入的位置
                while (j >= l && A[j] > tmp)
                {
                    swap(&A[j], &A[j + d]);
                    j = j - d;
                }
                A[j + d] = tmp;
            }
        }
    }
}