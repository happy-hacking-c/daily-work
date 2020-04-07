
/**
 * 统计输入内容中单词长度的信息并绘制水平、垂直直方图
 * 郑凯
 * 2020年04月05日18:40:51
 * */

#include <stdio.h>

#define IN 1 //单词内
#define OUT 0 //单词外
#define MAX_LENGTH 10 //最长单词长度

int main()
{
    int wordsLenth[11]; //假设单词长度最长为10
    int c, cc, w, wl, state; //字符，单词, 词长，状态

    cc = w = wl = 0;

    state = OUT;
    //不断从输入字符流中读取字符数据，直到结束
    while(( c = getchar()) != EOF) {

        //字符计数
        cc++;

        if(c == ' ' || c == '\n' || c == '\t' || c == ',' || c == '.' || c == '!' || c == '?') {
            //如果单从从单词内切换到单词外，改变状态，并更改该单词长度对应计数器+1
            state = OUT;
            if (wl <= MAX_LENGTH)
                wordsLenth[wl]++;
            //printf(" (%d) \n", wl);
            wl = 0;
            
        }
        else if ( state == OUT ) {
            //从单词外进入到单词内，改变状态并计数加1
            state = IN;
            //printf("%c", c);
            wl++;
            w++;
        } else {
            //printf("%c", c);
            wl++;
        }
    }

    //单词数
    //printf("words counts: %d", w);

    //计算长度最多的数量值（决定直方图最大范围）
    int maxCounts;
    for(int m = 1; m < MAX_LENGTH; m++) {
        if(wordsLenth[m] > maxCounts) {
            maxCounts = wordsLenth[m];
        }
    }

    //绘制水平方向直方图
    printf("水平直方图：\n");
    int i, lengthTemp;
    for( i = 1 ; i<= MAX_LENGTH ; i++) {
        printf("%3d  ", i);
        lengthTemp = wordsLenth[i];
        while (lengthTemp > 0)
        {
            printf(" * ");
            lengthTemp--;
        }
        printf("\n");

    }
    //打印横坐标
    printf("le/co");
    for( i = 1 ; i <= maxCounts ; i++) {
       printf(" %d ",i);
    }
    printf("\n");
    

    //绘制垂直直方图
    printf("垂直直方图：\n");
    int x,y;
    for( y = maxCounts ; y >= 0 ; y--) {
        y > 0 ? printf("  %2d ", y) : printf("co/le");
        for ( x = 1 ; x <= MAX_LENGTH ; x++ ) {
            if( y > 0 && y - wordsLenth[x] <= 0) {
                printf(" * ");
            }else if(y > 0 && y - wordsLenth[x] > 0) {
                printf("   ");
            }else if(y == 0) {
                printf(" %d ", x);
            }
        }
        printf("\n");
    }

    return 0;
}