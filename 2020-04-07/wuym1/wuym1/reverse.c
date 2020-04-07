//
//  reverse.c
//  wuym1
//
//  Created by min on 2020/4/7.
//  Copyright © 2020 min. All rights reserved.
//

#include "reverse.h"

void reverse(char line[]) {
    int tmp;
    int max = 0;
    
    while (line[max] != '\0') {
        max++;
    }
    
    for (int i = 0; i <= max / 2; i++) {
        tmp = line[i];
        line[i] = line[max - i - 1];
        line[max - i - 1] = tmp;
    }
}

int mygetline(char s[], int lim) {
    int c, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    
    return i;
}
