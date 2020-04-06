
/**
 * 将输入的字符颠倒顺序之后输出出来
 * 郑凯
 * 2020年4月6日15:02:47
 * */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 //最长接受输入的字符长度，超过该长度将被截断处理

char input[MAX_LENGTH]; //输入字符串
char output[MAX_LENGTH]; //输出字符串
int charCounts; //统计输入字符数

//函数声明(函数原型)
void reverse(void);
int readLine(void);
void emptyArray(void);

//清空数组
void emptyArray(void)
{
    //数组“清空”函数
    memset(input, ' ', MAX_LENGTH);
    memset(output, ' ', MAX_LENGTH);
}

//将原字符串顺序颠倒
void reverse(void)
{
    int j = charCounts-1 ;
    for( int i = 0; i < charCounts; i++ ) {
         output[j] = input[i];
         j--;
    }

}

//读取一行数据
int readLine(void)
{
    //字符，统计该行字符数
    int c, i; 

    //清空输入数组
    emptyArray();

    //不断从输入字符流中读取字符数据，直到结束
    while(( c = getchar()) != EOF && i <= MAX_LENGTH && c != '\n' ) {
        input[i] = c;
        i++;
    }

    //如果一行输入结束
    if( c == '\n') {
        input[i] = c;
        i++;
    }

    //显示的将文本结束掉，增加结束符，以便输出函数知道字符串何时结束
    input[i] = '\0';
    
    //字符数
    return i;
}


int main()
{

    //字符
    int c; 

    //可以循环接收字符串输入
    while (1)
    {

        //控制台信息
        printf("请您输入一行文本信息，最大长度%d, 超过此长度的部分将被自动截断处理（Ctrl+C退出程序）：\n", MAX_LENGTH);
    
        //读取一行信息，并获取长度
        charCounts = readLine();

        //将输入字符串进行顺序颠倒
        reverse();

        //输出处理结果，数量去除掉换行符
        printf("您一共输入了%d 个字符，书序颠倒输出之后的结果如下：", charCounts-1);

        int i = 0;
        while (output[i] != '\0') {
            printf("%c", output[i]);
            i++;
        }
        printf("\n");

    }

    //退出程序
    printf("退出成功\n");
    return 0;
}