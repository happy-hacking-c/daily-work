//
//  main.c
//  wuym1
//
//  Created by min on 2020/4/9.
//  Copyright © 2020 min. All rights reserved.
//

#include <stdio.h>
#include "string.h"

int any(char s1[], char s2[]) {
    int i = 0, first = -1;
    while (s2[i] != '\0') {
        int j = 0;
        while (s1[j] != '\0') {
            if (s1[j] == s2[i]) {
                if (first == -1 || first > j) {
                    first = j;
                }
            }
            j++;
        }
        i++;
    }
    
    return first;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char s1[] = "abcdefg";
    char s2[] = "tegb";
    
    printf("%s中的字符第一次出现在%s的第%d位\n", s2, s1, any(s1, s2));
    
    return 0;
}
