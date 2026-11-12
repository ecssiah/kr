#include <stdio.h>

main()
{
    int c;
    int string_active = 0;
    int comment_active = 0;

    char prev_char = '\0';

    while ((c = getchar()) != EOF)
    {
        if (comment_active)
        {
            if (prev_char == '*' && c == '/')
            {
                comment_active = 0;
            }
        }
        else
        {
            if (string_active)
            {
                if (c == '"')
                {
                    string_active = 0;
                }

                putchar(c);
            }
            else
            {
                if (c == '"')
                {
                    if (prev_char != '\'')
                    {
                        string_active = 1;
                    }

                    putchar(c);
                }
                else
                {
                    if (prev_char == '/' && c == '*')
                    {
                        comment_active = 1;
                    }
                    else if (c != '/')
                    {
                        putchar(c);
                    }
                }
            }
        }

        prev_char = c;
    }

    return 0;
}
