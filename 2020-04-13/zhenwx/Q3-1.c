#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low <= high && x != v[mid])
    {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }

    if (x == v[mid])
        return mid;
    else
        return -1;
}

int main()
{
    int x = 6;
    int v[] = {1, 2, 4, 6, 8, 10, 12, 14};
    int n = 5;

    int i = 0;
    while (i++ < 10)
    {
        int begintime;
        begintime = clock();
        printf("\n#%d binsearch() = %d, Running Time：%lu\n", i, binsearch(x, v, n), clock() - begintime);

        begintime = clock();
        printf("#%d binsearch2() = %d, Running Time：%lu\n", i, binsearch2(x, v, n), clock() - begintime);
    }

    return 0;
}