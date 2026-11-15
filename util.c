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