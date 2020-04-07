//
//  str_replace.c
//  wuym1
//
//  Created by min on 2020/4/6.
//  Copyright © 2020 min. All rights reserved.
//

#include "str_replace.h"

void str_replace() {
    printf("str replace\n");
    
    int c;
    int i = 1;
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            i = 1;
            if (c == '\t') {
                printf("\\t");
            } else {
                putchar(c);
            }
        } else if (c == ' ' && i == 1) {
            i++;
            putchar(c);
        }
    }
}
