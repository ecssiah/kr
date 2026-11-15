#include <stdio.h>
#include <limits.h>

void 
print_binary(unsigned int n)
{
    char digits[sizeof n * CHAR_BIT];
    int count = 0;

    do 
    {
        digits[count++] = (n & 1U) ? '1' : '0';
        n >>= 1;
    }
    while (n != 0);

    while (count > 0)
    {
        putchar(digits[--count]);
    }

    putchar('\n');
}

unsigned
invert(unsigned x, int p, int n)
{
    unsigned right  = x & ~(~0 << (p + 1 - n));
    unsigned mid    = (~x >> (p + 1 - n)) & ~(~0 << n);
    unsigned left   = (x >> p + 1);

    unsigned result;

    result = left;
    result = (result << n) | mid;
    result = (result << (p + 1 - n)) | right;

    return result;
}

main()
{
    unsigned x1 = 0b10100101;

    unsigned r1 = invert(x1, 7, 3);
    unsigned r2 = invert(x1, 6, 3);
    unsigned r3 = invert(x1, 5, 3);
    unsigned r4 = invert(x1, 4, 3);
    unsigned r5 = invert(x1, 3, 3);
    unsigned r6 = invert(x1, 2, 3);

    print_binary(x1);
    putchar('\n');

    putchar('0'); print_binary(r1);
    print_binary(r2);
    print_binary(r3);
    print_binary(r4);
    print_binary(r5);
    print_binary(r6);

    return 0;
}