#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void clean(char in[], char out[]);

main()
{
    int length;

    char line[MAXLINE];
    char line_cleaned[MAXLINE];

    while ((length = getline(line, MAXLINE)) != EOF)
    {
        if (length > 0)
        {
            clean(line, line_cleaned);
            printf("%s", line_cleaned);
        }
    }

    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF) 
    {
        if (c == '\n' || i >= lim - 1)
        {
            s[i + 0] = '\n';
            s[i + 1] = '\0';

            return i;
        }
        else if (i > lim - 2)
        {
            s[i + 0] = '\n';
            s[i + 1] = '\0';

            return lim;
        }
        else
        {
            s[i] = c;
            ++i;
        }
    }

    return EOF;
}

void clean(char in[], char out[])
{
    int i;
    int in_length;
    int has_newline;

    i = in_length = 0;

    while (in[i] != '\0')
    {
        ++in_length;
        ++i;
    }

    if (in[in_length - 1] == '\n')
    {
        has_newline = 1;
        --in_length;
    }
    else
    {
        has_newline = 0;
    }

    while (
        in_length > 0 && 
        (in[in_length - 1] == ' ' || in[in_length - 1] == '\t')
    )
    {
        --in_length;
    }

    for (i = 0; i < in_length; ++i)
    {
        out[i] = in[i];
    }

    if (has_newline == 1)
    {
        out[i++] = '\n';
    }

    out[i] = '\0';
}