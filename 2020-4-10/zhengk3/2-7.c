
/**
 * 第四堂课作业：2-7
 * 郑凯
 * 2020年4月10日12:23:28
 * */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//函数声明
unsigned invert(unsigned x, int p, int n);
int getSetMid(int p, int n);

//函数实现：获取实现将开始处理处n个宽度位置1的值
int getSetMid(int p, int n)
{
    int mid = 0;
    for(--n; n >= 0; n--) {
        mid += pow(2, p - n);

    }

    return mid;
}

//函数实现：主体函数算法
unsigned invert(unsigned x, int p, int n)
{
    
    unsigned inverted = 0;
    //判断调用是否合法
    if( ( p - n + 1) >= 0 ) {
        unsigned a, b;

        //作用：处理长度n位外的全部高位全部置1
        //计算：把对应的二进制转为十进制，即当n=4时，1111的十进制数，即2n次方-1
        int set_high = pow(2, n) - 1;
    
        //作用：移动位宽（p-n+1）低位全部置1
        //计算：把对应的二进制转为十进制，即当p=6，n=4时，111的十进制数，即2（p-n+1）次方-1
        int set_low = pow(2, p-n+1) - 1;

        //作用：把第p位开始的n置为1，得到大公式里的B
        //计算：把对应的二进制转为十进制，即当p=6，n=4时，1111000的十进制数，即2的p-n(--n)次方之和
        int set_mid = getSetMid(p ,n);


        //处理计算
        a = (( ~ (x >> (p - n + 1)) | ~set_high ) << (p - n + 1)) | set_low;
        b = x | set_mid;

        inverted = a & b;
    }
    
    return inverted;

}


int main()
{

    //unsigned占4个字节，32位
    unsigned x = 1483; //10111001011
    char in[33];
    char out[33];

    //打印转换前的二进制数排列
    itoa(x,in,2);
    printf("转换前，二进制序列如下：\n%s\n",in);

    //调用处理函数
    unsigned result;
    if(result = invert(x , 5, 3)) {
        //打印转换后的二进制数排列
        itoa(result,out,2);
        printf("转换后，二进制序列如下：\n%s\n",out);
    }else{
        printf("参数非法\n");
    }

    return 0;
}
