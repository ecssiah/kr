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
setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned right  = x & ~(~0 << (p + 1 - n));
    unsigned mid    = y & ~(~0 << n);
    unsigned left   = (x >> p + 1);

    unsigned result;

    result = left;
    result = (result << n) | mid;
    result = (result << (p + 1 - n)) | right;

    return result;
}

main()
{
    unsigned x1 = 0b11110011;
    unsigned y1 = 0b11101010;

    unsigned r1 = setbits(x1, 7, 3, y1);
    unsigned r2 = setbits(x1, 6, 3, y1);
    unsigned r3 = setbits(x1, 5, 3, y1);
    unsigned r4 = setbits(x1, 4, 3, y1);
    unsigned r5 = setbits(x1, 3, 3, y1);
    unsigned r6 = setbits(x1, 2, 3, y1);

    putchar('0'); print_binary(r1);
    print_binary(r2);
    print_binary(r3);
    print_binary(r4);
    print_binary(r5);
    print_binary(r6);

    return 0;
}