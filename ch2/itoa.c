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
itoa(int n, char s[])
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
        if (min)
        {
            min = 0;
            s[i++] = (n % 10) + 1 + '0';
        }
        else
        {
            s[i++] = n % 10 + '0';
        }
    }
    while ((n /= 10) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
}

main()
{
    char s1[20];
    int n1 = 123456;

    char s2[100];
    int n2 = INT_MIN;

    char s3[100];
    int n3 = INT_MAX;

    itoa(n1, s1);
    itoa(n2, s2);
    itoa(n3, s3);

    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);

    return 0;
}