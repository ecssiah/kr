#include <stdio.h>

main()
{
    int c;
    int newline_count, tab_count, blank_count;

    newline_count = 0;
    tab_count = 0;
    blank_count = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            newline_count++;
        }
        else if (c == 't')
        {
            tab_count++;
        }
        else if (c == ' ')
        {
            blank_count++;
        }
    }

    printf(
        "Blanks: %d\nTabs: %d\nNewlines: %d\n", 
        blank_count, tab_count, newline_count
    );
}
