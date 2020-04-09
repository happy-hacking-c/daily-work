//
// Created by cotton on 2020/4/9.
//
#include <stdio.h>
#define LIMIT 500

void getLine(char s[]);
long htoi(char s[]);
int getLen(char s[]);
int getVal(char s);
int checkH(char s[]);

int main() {
    char s[LIMIT];
    long r;
    getLine(s);

    //检查输入的字符是否合法
    if (checkH(s) == -1) {
        printf("字符串%s不合法\n", s);
        return 1;
    }

    r = htoi(s);
    printf("%s = %ld\n", s, r);
    return 0;
}


void getLine(char s[]) {
    int i, c;
    for (i = 0; i < LIMIT - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    s[i] = '\0';
}

long htoi (char s[]){
    int i, n;
    long r = 0;
    i = 2;
    for (n = 0; s[i] != '\0'; n++) {
        r = r * 16 + getVal(s[i++]);
    }
    return r;
}

int getLen(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

int getVal(char s){
    if (s >= '0' && s <= '9') {
        return s - '0';
    } else if (s >= 'A' && s <= 'F') {
        return s - 'A' + 10;
    } else if (s >= 'a' && s <= 'f') {
        return s - 'a' + 10;
    } else {
        return -1;
    }
}

int checkH(char s[]){
    int i;

    if (getLen(s) < 3)
        return -1;

    if (s[0] != '0')
        return -1;

    if (s[1] != 'x' && s[1] != 'X')
        return -1;

    for (i = 2; s[i] != '\0'; i++) {
        if (getVal(s[i]) == -1)
            return -1;
    }
    return 1;
}








