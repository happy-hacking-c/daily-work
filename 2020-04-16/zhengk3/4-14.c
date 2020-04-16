
/**
 * 第8堂课作业：4-14
 * 郑凯
 * 2020年4月16日
 * */

#include <stdio.h>
#include <string.h>

#define swap(t, x, y) t tp; tp = x; x = y; y = tp;
#define myPrint(x) printf(#x " = %d\n", x);

int main()
{

    // int a = 100;
    // int b = 50;

    // swap(int, a, b);

    // myPrint(a);
    // myPrint(b);


    char c = 'a';
    char d = 'b';

    swap(char, c, d);

    myPrint(c);
    myPrint(d);


    return 0;
}


