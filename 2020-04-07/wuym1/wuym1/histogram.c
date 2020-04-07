//
//  histogram.c
//  wuym1
//
//  Created by min on 2020/4/6.
//  Copyright © 2020 min. All rights reserved.
//

#include "histogram.h"

#define IN 1
#define OUT 0
#define LENGTH 3

void histogram() {
    int c;
    int i = -1, len = 0, max = 0;
    short state = OUT;
    int word[LENGTH];
    
    while ((c = getchar()) != '\n') {
        if (c == ' ') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            len = 1;
            i++;
        } else if (state == IN) {
            len++;
            word[i] = len;
            if (len > max) {
                max = len;
            }
        }
    }
    
    for (int j = max; j > 0; j--) {
        for (i = 0; i < LENGTH; i++) {
            if (word[i] < j) {
                printf("  ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}
