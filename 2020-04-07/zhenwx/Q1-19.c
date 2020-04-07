#include <stdio.h>

#define MAXLINE 1000

void reverse(char line[]);
int getLine(char line[], int max);

//库函数声明
size_t strlen(const char *str);

int main(){
    char line[MAXLINE];

    while (getLine(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}

//字符串反转
void reverse(char line[]){
    int end= strlen(line);
    char tmp;
    for (int start = 0; start < end; start++) {
        end--;
        tmp = line[end];
        line[end] = line[start];
        line[start] = tmp;
    }
}

//读取字符串
int getLine(char line[], int max){
    int c, i;
    for (i = 0; i < max - 1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        ++i;
    }

    line[i] = '\0';
    return i;
}