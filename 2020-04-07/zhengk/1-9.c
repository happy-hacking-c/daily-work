
/**
 * 把输入的内容进行输出，并把连续空格替换为1个空格
 * 郑凯
 * 2020年04月05日18:12:06
 * */

#include <stdio.h>

int main()
{
    int char_space; //空格数
    int c; //字符

    char_space = 0;

    //不断从输入字符流中读取字符数据，直到结束
    while(( c = getchar()) != EOF) {

        if(c == ' ')
           char_space++;

        //如果不是连续空格出现，将字符赋值给要输出的字符串中；
        if(char_space < 2) {
            printf("%c", c);

        }else if(c != ' ') {
            char_space = 0;

        }

    }

    return 0;
}