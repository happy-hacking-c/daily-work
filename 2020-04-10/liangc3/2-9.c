//
// Created by cotton on 2020/4/10.
//

#include <stdio.h>

int bitcount(unsigned x);

int main() {
    printf("%d\n", bitcount(254));
    return 0;
}

//因为如果最右边的1的右边还有数的话，哪些数必然是零，-1的话，借位必然会借到最右的1那里，借位后1就变成0了。按位与的话，从最右的1开始往右必然是0.
int bitcount(unsigned x) {
    int count;
    for (count = 0; x > 0; x &= (x -1)) {
        count++;
    }
    return count;
}



