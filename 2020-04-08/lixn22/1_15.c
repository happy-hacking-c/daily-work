#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void temp();

void main()
{
    temp();
}

void temp()
{
    float fahr, cels;
    fahr = LOWER;

    while (fahr <= UPPER)
    {
        cels = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f  %6.1f\n", fahr, cels);
        fahr += STEP;
    }
}
