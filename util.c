#include <stdio.h>
#include <string.h>
#include <limits.h>

void 
reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) 
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

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