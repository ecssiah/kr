#include <stdio.h>
#include <string.h>
#include <math.h>

#define HEX_BASE 16

int
htoi(char s[])
{
    int i = 0;
    int result = 0;
    int len = strlen(s);
    int place = len - 1;

    if (len >= 3)
    {
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        {
            i = 2;
            place -= 2;
        }
    }

    for ( ; i < len; ++i)
    {
        int value = 0;

        if (s[i] >= 'a' && s[i] <= 'f')
        {
            value = s[i] - 'a' + 10;
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            value = s[i] - 'A' + 10;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            value = s[i] - '0';
        }

        result += pow(HEX_BASE, place) * value;
        --place;
    }

    return result;
}

main()
{
    char t1[] = "0x2f";
    char t2[] = "0X2F";
    char t3[] = "2f";
    char t4[] = "2F";

    char t5[] = "0xffff";
    char t6[] = "0XFFFF";
    char t7[] = "ffff";
    char t8[] = "FFFF";

    int r1 = htoi(t1);
    int r2 = htoi(t2);
    int r3 = htoi(t3);
    int r4 = htoi(t4);

    int r5 = htoi(t5);
    int r6 = htoi(t6);
    int r7 = htoi(t7);
    int r8 = htoi(t8);

    printf("%d %d %d %d\n", r1, r2, r3, r4);
    printf("%d %d %d %d\n", r5, r6, r7, r8);

    return 0;
}