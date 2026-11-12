#include <stdio.h>

main()
{
    int i, c;
    int char_count[26];

    for (i = 0; i < 26; ++i)
    {
        char_count[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            ++char_count[c - 'a'];
        }
        else if (c >= 'A' && c <= 'Z')
        {
            ++char_count[c - 'A'];
        }
    }

    for (c = 'A'; c <= 'Z'; ++c)
    {
        printf("%c  ", c);

        for (i = 0; i < char_count[c - 'A']; i += 1)
        {
            printf("#");
        }

        printf("\n");
    }
}