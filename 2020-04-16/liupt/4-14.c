#include <stdio.h>

#define swap(t,x,y) \
    t tmp; \
    tmp = x; \
    x = y; \
    y = tmp; \


int main(){
    int x = 1;
    int y = 2;
    printf("before x = %d y = %d \n",x,y);

    swap(int,x,y);

    printf("before x = %d y = %d \n",x,y);


    return 0;
}