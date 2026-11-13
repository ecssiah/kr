#include <stdio.h>
#include <limits.h>
#include <float.h>

void
char_range()
{
    signed char schar_min = 0, schar_max = 0;

    while ((signed char)(schar_min - 1) < 0)
    {
        --schar_min;
    }

    schar_max = schar_min - 1;

    unsigned char uchar_max = 0;
    --uchar_max;

    printf("Ref Signed Char (min: %d max: %d)\n", SCHAR_MIN, SCHAR_MAX);
    printf("Cal Signed Char (min: %d max: %d)\n\n", schar_min, schar_max);

    printf("Ref Unsigned Char (min: 0 max: %d)\n", UCHAR_MAX);
    printf("Cal Unsigned Char (min: 0 max: %d)\n\n", uchar_max);
}

void
short_range()
{
    signed short sshort_min = 0, sshort_max = 0;

    while ((signed short)(sshort_min - 1) < 0)
    {
        --sshort_min;
    }

    sshort_max = sshort_min - 1;

    unsigned short ushort_max = 0;
    --ushort_max;

    printf("Ref Signed Short (min: %d max: %d)\n", SHRT_MIN, SHRT_MAX);
    printf("Cal Signed Short (min: %d max: %d)\n\n", sshort_min, sshort_max);

    printf("Ref Unsigned Short (min: 0 max: %d)\n", USHRT_MAX);
    printf("Cal Unsigned Short (min: 0 max: %d)\n\n", ushort_max);
}

void
int_range()
{
    signed int sint_min = 0, sint_max = 0;

    signed int delta = 1 << 16;

    while (1)
    {
        if ((signed long)(sint_min - delta) > 0)
        {
            delta /= 2;

            if (delta == 1)
            {
                while ((signed long)(sint_min - 1) > 0)
                {
                    --sint_min;
                }

                break;
            }
        }
        else
        {
            sint_min -= delta;
        }
    }

    sint_max = sint_min - 1;

    unsigned int uint_max = 0;
    --uint_max;

    printf("Ref Signed Int (min: %d max: %d)\n", INT_MIN, INT_MAX);
    printf("Cal Signed Int (min: %d max: %d)\n\n", sint_min, sint_max);

    printf("Ref Unsigned Int (min: 0 max: %u)\n", UINT_MAX);
    printf("Cal Unsigned Int (min: 0 max: %u)\n\n", uint_max);
}

void
long_range()
{
    signed long slong_min = 0, slong_max = 0;

    signed long delta = 1L << 42;
    
    while (1)
    {
        if ((signed long)(slong_min - delta) > 0)
        {
            delta /= 2;
            
            if (delta == 1)
            {
                while ((signed long)(slong_min - 1) > 0)
                {
                    --slong_min;
                }
                
                break;
            }
        }
        else
        {
            slong_min -= delta;
        }
    }

    slong_max = slong_min - 1;
    
    unsigned long ulong_max = 0;
    --ulong_max;
    
    printf("Ref Signed Long (min: %ld max: %ld)\n", LONG_MIN, LONG_MAX);
    printf("Cal Signed Long (min: %ld max: %ld)\n\n", slong_min, slong_max);
    
    printf("Ref Unsigned Long (min: 0 max: %lu)\n", ULONG_MAX);
    printf("Cal Unsigned Long (min: 0 max: %lu)\n\n", ulong_max);
}

main()
{
    char_range();
    short_range();
    int_range();
    long_range();

    return 0;
}
