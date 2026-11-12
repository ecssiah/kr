#include <stdio.h>

#define TAB_COLUMNS 4

main()
{
    int i, c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            for (i = 0; i < TAB_COLUMNS; ++i)
            {
                printf(" ");
            }
        }
        else 
        {
            printf("%c", c);
        }
    }

    return 0;
}