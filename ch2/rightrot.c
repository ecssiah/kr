#include <stdio.h>
#include <limits.h>

void 
printb(unsigned n)
{
    unsigned width = sizeof(UINT_MAX) * CHAR_BIT;
    unsigned mask = 1 << (width - 1);

    while (mask != 0U)
    {
        putchar((n & mask) ? '1' : '0');
        mask >>= 1;
    }

    putchar('\n');
}

unsigned
rightrot(unsigned x, int n)
{
    unsigned width = sizeof(UINT_MAX) * CHAR_BIT;

    unsigned left   = x >> n;
    unsigned right  = x & ~(~0 << n);

    unsigned result;

    result = right;
    result = (result << (width - n)) | left;

    return result;
}

main()
{
    unsigned x1 = 0b1010101010101010;

    unsigned r0 = rightrot(x1, 0);
    unsigned r1 = rightrot(x1, 1);
    unsigned r2 = rightrot(x1, 2);
    unsigned r3 = rightrot(x1, 3);
    unsigned r4 = rightrot(x1, 4);
    unsigned r5 = rightrot(x1, 5);
    unsigned r6 = rightrot(x1, 6);
    unsigned r7 = rightrot(x1, 7);
    unsigned r8 = rightrot(x1, 8);

    printb(x1);
    putchar('\n');

    printb(r0);
    printb(r1);
    printb(r2);
    printb(r3);
    printb(r4);
    printb(r5);
    printb(r6);
    printb(r7);
    printb(r8);

    return 0;
}