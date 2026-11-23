#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

float getfloat(float *pn)
{
    int c, sign;
    
    while (isspace(c = getch()));
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0.0;
    }

    sign = (c == '-') ? -1.0 : 1.0;

    if (c == '+' || c == '-')
    {
        c = getch();
    }

    for (*pn = 0.0; isdigit(c); c = getch())
    {
        float fc = c - '0';
        *pn = 10.0 * *pn + fc;
    }
    
    if (c == '.')
    {
        float m = 0.1;

        for (c = getch(); isdigit(c); c = getch())
        {
            float fc = c - '0';
            *pn += m * fc;

            m /= 10.0;
        }
    }

    *pn *= sign;

    if (c != EOF)
    {
        ungetch(c);
    }

    return c;
}

#define SIZE    100

main()
{
    int n, c;
    float array[SIZE];

    for (n = 0; n < SIZE; n++)
    {
        array[n] = 0.0;
    }

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++);

    c = n;

    for (n = 0; n < c; n++)
    {
        printf("%.2f\n", array[n]);
    }

    return 0;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int
getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void
ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
