
/**
 * 把输入的内容进行输出，并把制表符、回退符、反斜杠进行替换
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

        //如果不是连续空格出现，将字符赋值给要输出s的字符串中；
        if(char_space < 2) {

            //替换
            switch (c)
            {
            case '\t':
                printf("\t");
                break;
            case '\b':
                printf("\b");
                break;
            case '\\':
                printf("\\\\");
                break;    
            default:
                printf("%c", c);
                break;
            }
            

        }else if(c != ' ') {
            char_space = 0;

        }

    }

    return 0;
}