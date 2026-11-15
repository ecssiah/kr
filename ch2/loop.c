#include <stdio.h>

main()
{
    char i = 0, c;
    int lim = 20;

    char s[20];

    while (1)
    {
        if (i > lim - 1)
        {
            break;
        }
        else
        {
            if ((c = getchar()) == '\n')
            {
                break;
            }            
            
            if (c == EOF)
            {
                break;
            }

            s[i++] = c;
        }
    }

    s[i] = '\0';

    printf("%s\n", s);

    return 0;
}
