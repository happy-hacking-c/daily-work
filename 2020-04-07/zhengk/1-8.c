
/**
 * 统计输入内容中空格、制表符、换行符个数
 * 郑凯
 * 2020年04月05日17:35:22
 * */

#include <stdio.h>

int main()
{
    int char_space; //空格数
    int char_table; //制表符
    int char_line; //换行符
    int char_counts; //字符数
    int c; //字符

    char_space = char_table = char_line = 0;

    while(( c = getchar()) != EOF) {

        switch (c)
        {
            //换行符
            case '\n':
                char_line++;
                break;
            //制表符
            case '\t':
                char_table++;
                break;
            //空格
            case ' ':
                char_space++;
                break;

            default:
                char_counts++;
        }

        //printf("char is : %d", c);
    }

    printf("the data of this string print follwing:\n");
    printf("Empty Space Counts:%d \n", char_space);
    printf("Line Counts:%d \n", char_line);
    printf("Table Char Counts:%d \n", char_table);
    printf("Word Counts:%d \n", char_counts);

    return 0;
}