#include <stdio.h>
#include "../util.c"

// FIX: Limits are not handled correctly in non-decimal bases
void
itob(int n, char s[], int b)
{
    int min;
    int i, sign;

    if (min = (n == INT_MIN))
    {
        sign = -1;

        n += 1;
        n = -n;
    }
    else if ((sign = n) < 0)
    {
        n = -n;
    }

    i = 0;

    do
    {
        char c;

        if (min)
        {
            min = 0;
            c = (n % b) + 1;
        }
        else
        {
            c = n % b;
        }

        if (c < 10)
        {
            s[i++] = c + '0';
        }
        else
        {
            s[i++] = c - 10 + 'A';
        }
    }
    while ((n /= b) > 0);

    switch (b)
    {
        case 2:
            s[i++] = 'b';
            s[i++] = '0';
            break;
        case 8:
            s[i++] = '0';
            break;
        case 16:
            s[i++] = 'x';
            s[i++] = '0';           
            break;
        default:
            break;
    }

    if (sign < 0)
    {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
}

main()
{
    int n1 = 2048;

    char s1[100];
    char s2[100];
    char s3[100];
    char s4[100];

    itob(n1, s1, 2);
    itob(n1, s2, 8);
    itob(n1, s3, 10);
    itob(n1, s4, 16);

    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);
    printf("%s\n", s4);

    return 0;
}