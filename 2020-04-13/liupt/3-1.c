#include <stdio.h>


int binsearch(int x, int v[], int n);

int main() {
    
    int v[12] = {0, 1, 3, 5, 8, 10, 15, 22, 25, 30, 33, 45};
    printf("size %lu\n",  sizeof(v)/sizeof(v[0]));
    printf("index %d\n", binsearch(15, v, sizeof(v)/sizeof(v[0])));
    
    return 0;
}


int binsearch(int x, int v[], int n) {
    if (n < 1) {
        return -1;
    }
    
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (v[mid] != x && low <= high) {
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    
    if (v[mid] == x) {
        return mid;
    }
    return -1;
}

