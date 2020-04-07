//
//  main.c
//  wuym1
//
//  Created by min on 2020/4/3.
//  Copyright © 2020 min. All rights reserved.
//

#include <stdio.h>

#define MAXLINE 1000

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int len;
    char line[MAXLINE];
    
    while ((len = mygetline(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s\n", line);
    }
    
    return 0;
}
