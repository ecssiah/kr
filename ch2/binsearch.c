#include <stdio.h>

int
binsearch2(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (x < v[mid])
        {
            high = mid + 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int
binsearch1(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n;

    while (low < high)
    {
        mid = low + (high - low) / 2;

        if (v[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    if (low < n && v[low] == x)
    {
        return low;
    }

    return -1;
}

main()
{
    int v1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int r1 = binsearch2(2, v1, 10);
    int r2 = binsearch1(2, v1, 10);

    printf("2: %d\n1: %d\n", r1, r2);

    return 0;
}