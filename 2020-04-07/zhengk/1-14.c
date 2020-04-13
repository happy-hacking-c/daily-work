
/**
 * 统计输入字符串各个字符出现频度的直方图
 * 郑凯
 * 2020年4月6日20:01:43
 * */

#include <stdio.h>

#define MAX_LENGTH 100 //设置最多处理的字符串长度
#define CHAR_COUNTS 128 //标准ASCII字符集到目前为止共定义128中字符

int wordBox[CHAR_COUNTS]; //存储输入字符各字符的出现次数信息

int main()
{
    //控制台信息
    printf("请您输入一行文本信息，最大长度%d, 超过此长度的部分将被自动截断处理：\n", MAX_LENGTH);

    int c, j;

    //不断从输入字符流中读取字符数据，直到结束
    while(( c = getchar()) != EOF && j <= MAX_LENGTH) {
        wordBox[c] += 1;
        j++;
    }

    //绘制水平方向直方图
    printf("水平直方图：\n");
    
    int i,lengthTemp;
    for( i = 64 ; i < CHAR_COUNTS ; i++) {
        printf("%d  ", i);
        lengthTemp =10;
        while (lengthTemp > 0)
        {
            printf(" * ");
            lengthTemp--;
        }
        printf("\n");

    }
    //打印横坐标
    printf("ch/co");
    for( i = 0 ; i <= MAX_LENGTH ; i++) {
       printf(" %d ",i);
    }
    printf("\n");


    return 0;
    
}