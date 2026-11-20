#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int
getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch_x()) == ' ' || c == '\t');

    s[1] = '\0';



    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }

    i = 0;

    if (c == '-' || isdigit(c))
    {
        while (isdigit(s[++i] = c = getch_x()));
    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch_x()));
    }

    s[i] = '\0';

    if (c != EOF)
    {
        putch_x(c);
    }

    return NUMBER;
}
