#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline_x(char line[], int max);
int strindexr(char source[], char searchfor[]);

char pattern[] = "three";

main()
{
    char line[MAXLINE];

    while (getline_x(line, MAXLINE) > 0)
    {
        printf("%s\n", line);

        int index;

        index = strindexr(line, pattern);

        if (index == -1)
        {
            printf("Did not find: '%s'\n\n", pattern);
        }
        else
        {
            printf("Found '%s' at: %d/%d\n\n", pattern, index, strlen(line) - 1);
        }
    }

    return 0;
}

int
getline_x(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }

    if (c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';

    return i;
}

int
strindexr(char s[], char t[])
{
    int i, j, k;

    const int slen = strlen(s);
    const int tlen = strlen(t);

    for (i = slen - 1; i >= 0 && i >= tlen - 1; i--)
    {
        for (j = i, k = tlen - 1; k >= 0 && s[j] == t[k]; j--, k--);

        if (k == -1)
        {
            return i + 1 - tlen;
        }
    }

    return -1;
}
