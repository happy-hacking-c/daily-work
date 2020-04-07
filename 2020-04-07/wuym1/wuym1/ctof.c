//
//  ctof.c
//  wuym1
//
//  Created by min on 2020/4/6.
//  Copyright © 2020 min. All rights reserved.
//

#include "ctof.h"

void ctof() {
    printf("celsius to fahr transfer\n");
    
    float celsius, fahr;
    int lower, upper, step;
    lower = 0;
    upper = 200;
    step = 20;
    
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f\t%4.1f\n", celsius, fahr);
        celsius += step;
    }
}
