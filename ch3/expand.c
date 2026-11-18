#include <stdio.h>

void
expand(char s1[], char s2[])
{
    char c;
    int i, j = 0;

    for (i = 0; s1[i] != '\0'; ++i)
    {
        if (s1[i + 1] == '-')
        {
            char test[] = { 'a', 'z', 'A', 'Z', '0', '9', '\0' };

            int k;
            for (k = 0; test[k] != '\0'; k += 2)
            {
                if (s1[i] >= test[k] && s1[i] <= test[k + 1])
                {
                    if (s1[i + 2] >= s1[i] && s1[i + 2] <= test[k + 1])
                    {
                        for (c = s1[i]; c != s1[i + 2]; ++c)
                        {
                            s2[j++] = c;
                        }
    
                        ++i;
                    }
                    else
                    {
                        s2[j++] = s1[i];
                    }
                }
            }
        }
        else
        {
            s2[j++] = s1[i];
        }
    }

    s2[j] = '\0';
}

main()
{
    char t1[] = "z-aa-e0-3 A-Za-b-c test 4-9-a-z0-9";
    char t2[1000];

    expand(t1, t2);

    printf("%s\n", t1);
    printf("%s\n", t2);

    return 0;
}

