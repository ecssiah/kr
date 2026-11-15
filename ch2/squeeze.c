#include <stdio.h>

void
squeeze(char s[], char t[])
{
    int i, j, k;

    for (k = 0; t[k] != '\0'; ++k)
    {
        for (i = j = 0; s[i] != '\0'; ++i)
        {
            if (s[i] != t[k])
            {
                s[j++] = s[i];
            }
        }

        s[j] = '\0';
    }
}

main()
{
    char s1[] = "This is a test.";
    char t1[] = "si";

    squeeze(s1, t1);

    printf("%s\n", s1);

    return 0;
}