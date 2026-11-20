#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int
getch_x(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void
putch_x(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("putch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

