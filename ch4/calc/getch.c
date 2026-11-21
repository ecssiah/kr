#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int
getchx(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void
putchx(int c)
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
