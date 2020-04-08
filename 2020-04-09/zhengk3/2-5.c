
/**
 * 第三堂课作业：字符串位置寻找函数
 * 郑凯
 * 2020年4月8日20:25:04
 * */

#include <stdio.h>

#define STRONE "my name is zhengkai! im is a c programer! do you want to know why my name is zhengkai?"
#define STRTWO "zhengkai"
#define NONE -1

//函数声明
int any(char s[], char t[]);

//函数实现
int any(char s[], char t[])
{
    int pos = NONE;
    int j;
    for(int i = 0; s[i] != '\0'; i++ ) {
        for(j = 0; t[j] != '\0'; j++ ) {
            if(s[i] != t[j]) {
                //如果出现有字符不相同，说明不是被查找字符串，内部小循环重新进行，清空位置信息，跳出内部小循环，继续外部大循环
                j = 0;
                pos = NONE;
                break;
            }else{
                //说明截止目前，还是匹配的内容，记录第一次第一个字符相同的位置(从0开始)，并继续内部小循环
                if(j == 0 ) pos = i;
                i++;
            }
        }

        //如果已经找到(被循环字符串循环完毕)，终止外层大循环，不再继续匹配

        if(t[j] == '\0') break;
    }

    //返回位置信息
    return pos;
}


int main()
{

    char string_1[100] = STRONE;
    char string_2[10] = STRTWO;
    int pos;

    //输出信息
    if((pos = any(string_1, string_2)) != NONE) {
        printf("%s In %s 's position is : %d" ,  string_2, string_1, pos);
    }else{
        printf("%s In %s dosn't exit!" , string_2, string_1);

    }
    
    return 0;
}
