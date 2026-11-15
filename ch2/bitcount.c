#include <stdio.h>
#include "../util.c"

int
bitcount(unsigned n)
{
    unsigned count = 0;

    while (n != 0U)
    {
        n &= (n - 1);
        ++count;
    }

    return count;
}

main()
{
    unsigned x0 = 0b1010;
    unsigned x1 = x0 - 1;

    printb(x0);
    printb(x1);

    int c1 = bitcount(0b010101);
    int c2 = bitcount(0b01010);
    int c3 = bitcount(0b0101);
    int c4 = bitcount(0b010);
    int c5 = bitcount(0b01);
    int c6 = bitcount(0b0);

    printf("%d\n", c1);
    printf("%d\n", c2);
    printf("%d\n", c3);
    printf("%d\n", c4);
    printf("%d\n", c5);
    printf("%d\n", c6);

    return 0;
}