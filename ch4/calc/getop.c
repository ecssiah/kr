#include <stdio.h>
#include <ctype.h>
#include "calc.h"

static char pc = '\0';

int
getop(char s[])
{
    int i, c;

    if (pc != '\0' && pc != ' ')
    {
        c = pc;
        pc = '\0';
    }
    else 
    {
        while ((s[0] = c = getchx()) == ' ' || c == '\t');
    }

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
    {
        return c;
    }

    i = 0;

    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getchx()));
    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = getchx()));
    }

    s[i] = '\0';

    if (c != EOF)
    {
        pc = c;
    }

    return NUMBER;
}
