#include <stdio.h>

char
lower(char c)
{
    return (c >= 'A' && c <= 'Z') ? 'a' + (c - 'A') : c;
}

main()
{
    char t1[] = "This is a TEST, but it Might be Odd.";

    int i;
    for (i = 0; t1[i] != '\0'; ++i)
    {
        putchar(lower(t1[i]));
    }

    putchar('\n');

    return 0;
}