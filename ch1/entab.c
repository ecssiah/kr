#include <stdio.h>

#define TAB_COLUMNS 4

main()
{
    int c;
    int blank_count = 0;

    while (1)
    {
        c = getchar();

        if (c == ' ')
        {
            ++blank_count;
        }
        else
        {
            if (blank_count > 0)
            {
                int i;

                for (
                    i = 0; 
                    i < (blank_count / TAB_COLUMNS) * TAB_COLUMNS; 
                    i += TAB_COLUMNS
                )
                {
                    printf("\t");
                }

                for ( ; i < blank_count; ++i)
                {
                    printf(" ");
                }

                blank_count = 0;
            }

            if (c == EOF)
            {
                break;
            }
            else
            {
                printf("%c", c);
            }
        }
    }

    return 0;
}