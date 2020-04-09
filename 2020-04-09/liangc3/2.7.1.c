//
// Created by cotton on 2020/4/8.
//

#include <stdio.h>

int main() {
    char s[5] = "123";
    int i, n = 0;
    for (i = 0; s[i] > '0' && s[i] < '9'; i++)
        n = 10 * n + (s[i] - '0');
    printf("%d\n", n);
    return 0;
}
