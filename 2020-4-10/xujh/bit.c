static unsigned getbits(unsigned x, int p, int n) {
   return (x >> (p-n+1)) & ~(~0<<n); //错误操作 右操作数必须为0-正数
}

// 位sizeof(unsigned)<-0
static unsigned invert(unsigned x,int p,int n) {
//    int right = p-n+1;
//    __uint8_t t = getbits(x,p,n);
//    t <<=  right;
//    t = ~t;
//    __uint8_t t1 = x & t;
//    return t1;
    return x & ~(getbits(x,p,n)<<(p-n+1));
}

static size_t bitcount1(unsigned x) {
    size_t count = 0;
    while (x) {
        if(x & 0x1) {
            count++;
        }
        x >>= 1;
    };
    return count;
}

static size_t bitcount2(unsigned x) {
    size_t count = 0;
    while (x) {
        x &= x-1;
        count++;
    };
    return count;
}
//SSE4.2指令集 _mm_popcnt_u64 <nmmintrin.h>
