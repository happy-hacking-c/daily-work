
/**
 * 第四堂课作业：2-9
 * 郑凯
 * 2020年4月10日13:45:51
 * */

#include <stdio.h>



//函数声明
int bitcount(unsigned x);

//函数实现
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; b++) {
        x &= x - 1;
    }

    return b;
}


int main()
{

    //unsigned占4个字节，32位
    unsigned x = 1483; //10111001011
    
    bitcount(x);
    printf("%u 中bit个数是：\n%d\n",x , bitcount(x));

    return 0;
}
