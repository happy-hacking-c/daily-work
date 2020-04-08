#include <stdio.h>
#include <limits.h>

int main()
{
    printf("\n标准头文件输出\n");
    printf("Type Min~Max\n");
    printf("signedInt %d~%d\n", INT_MIN, INT_MAX);
    printf("unsignedInt %d~%u\n", 0, UINT_MAX);
    printf("signedLong %ld~%ld\n", LONG_MIN, LONG_MAX);
    printf("unsignedLong %d~%lu\n", 0, ULONG_MAX);
    printf("signedShort %d~%d\n", SHRT_MIN, SHRT_MAX);
    printf("unsignedShort %d~%d\n", 0, USHRT_MAX);
    printf("signedChar %d~%d\n", CHAR_MIN, CHAR_MAX);
    printf("unsignedChar %d~%d\n", 0, UCHAR_MAX);


    printf("\n直接计算输出\n");
    printf("Type Min~Max\n");
    int sin, sim;
    while (1)
    {
        sim++;
        if (sim + 1 < 0) {
            sin = sim +1;
            break;
        }
    }
    printf("signedInt %d~%d\n", sin, sim);

    unsigned int uim;
    while (1)
    {
        uim++;
        if (uim + 1 == 0) {
            break;
        }
    }
    printf("unsignedInt %d~%u\n", 0, uim);

    // 其他同理（有点慢，略）
}