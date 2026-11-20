#include <stdio.h>
#include <string.h>
#include "../util.c"

#define MAXLINE 1000

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
