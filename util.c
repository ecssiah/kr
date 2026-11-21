#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

int
getline_x(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }

    if (c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';

    return i;
}

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
