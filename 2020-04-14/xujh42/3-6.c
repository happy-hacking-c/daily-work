//
// Created by junhai on 2020/4/14.
//
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/**
 * char to int
 */
int atoi(const char s[]) {
    int i,n,sign;

    for(i = 0; isspace(s[i]);i++) //跳过空白符
        ;
    sign = (s[i] == '-') ? -1:1; //从第一个不为空格的位置开始
    if(s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (n = 0 ; isdigit(s[i]); i++){
        n = 10*n + (s[i] - '0'); //10倍递增，个十百千增；字符0之间的距离如：9（57-48）
    }
    return sign * n;
}

/**
 * n =》 s中 -8090 => 8090
 * @param n
 * @param s
 */
void itoa(int n,char s[],int w) {
    int sign,i = 0;
    if((sign = n) < 0 ){
        n = -n; //变为正数
        //s[i++] = '-';
    }

    //逆序生成
//    do {
//        s[i++] = n%10+'0'; //n对10的余数 0 + 47 => 字符0
//    }while ((n/=10)>0); //0908
//    if(sign < 0) {
//        s[i++] = '-';
//    }
//    s[i] = '\0';
    int count = 0,t = n; //位数
    while(t) {
        t /= 10;
        count++;
    }

    //符号算位数么？
    if(count < w) {
        for(int j=w-count;j>0;j--) {
            s[i++] = ' ';
        }
    }

    if(sign < 0) {
        s[i++] = '-';
    }

    int r;
    //正序
    do {
        r = n/pow(10,count-1);
        if(r == 0) {
            s[i++] = '0';
        } else {
            s[i++] = r+'0';
        }
        n -= r*pow(10,--count);
    } while (count>0 && i <= w);

    s[i] = '\0';
}

/**
 * 优化插入排序
 * 1.有序度越高的数组，插入排序工作量越少
 * 2.预处理比如8个元素数组，分别以（4，2，1）为跨度对数组分组4分成4个组，2分成2个组，当为1的时候就是插入排序，逐渐折半
 * @param s
 * 极端情况 等比增量 =》 Hibbard增量和Sedgewick增量
 * Hibbard的增量序列如下：
1，3，7，15......
通项公式 2^k-1
利用此种增量方式的希尔排序，最坏时间复杂度是O（n^(3/2)）

Sedgewick的增量序列如下：
1, 5, 19, 41, 109......
通项公式 9*4^k - 9*2^k + 1 或者 4^k - 3*2^k + 1
利用此种增量方式的希尔排序，最坏时间复杂度是O（n^(4/3)）
 */
void shellSort(int s[],int n){
    int i,j,tmp,gap = n; //希尔增量
    while ((gap = gap/2) >= 1) { //分组长度折半
        for(i = 0 ;i < gap; i ++) { //gap长度个分组
            for(j=i+gap;j < n;j += gap) { //分组元素
                //插入排序？ //仅仅交换？
                if(s[j] < s[j-gap]) {
                    tmp = s[j];
                    s[j] = s[j-gap];
                    s[j-gap] = tmp;
                }
            }
        }
    }
}

void testWhile(){
    int s[8] = {5,8,6,33,9,2,13,34};
    shellSort(s,8);
    for(int i = 0 ;i < 8; i++)
    {
        printf("%d ",s[i]);
    }
    printf("\n");
    const char *a = "    -83240";
    printf("atoi res:%d\n",atoi(a));

    char ia[20];
    itoa(-1,ia,4);
    printf("itoa res:%s,len:%d\n",ia,strlen(ia));
}
