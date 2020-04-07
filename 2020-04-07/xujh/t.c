//
// Created by junhai on 2020/4/7.
//
#include <stdio.h>

/**
 * 1-2
 * 当fahr为 0 ，29 打印对照表浮点数版本
 */
void testTem(){
    printf("这是一个转换程序\n");
    float fahr,celsius;
    int lower,upper,step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    while (fahr <= upper ) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f  %6.0f\n", fahr, celsius);
        fahr += step;
    }
}


#define UPPER 300
#define LOWER 0
#define STEP 20
/**
 * 1-5
 */
void testFor(){
    int fahr;
    for(fahr = UPPER;fahr > LOWER; fahr -= STEP){
        printf("%3d  %6.0f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}

/**
 * 1-6.7
 */
void testChar(){
    int c, nl,sl,tl;
    nl = sl = tl = 0;

    while ((c = getchar()) != EOF) {
        putchar(c);
        switch (c) {
            case '\n':
                ++nl;
            case ' ':
                ++sl;
            case '\t':
                ++tl;
        }
    }
}

int main(){
    printf("hello world\\g\n");
    testTem();
    testFor();
    testChar();
    return 0;
}

