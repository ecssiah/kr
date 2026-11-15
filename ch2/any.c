#include <stdio.h>

int
any(char s1[], char s2[])
{
    int k;
    int result = -1;

    for (k = 0; s2[k] != '\0'; ++k)
    {
        int i, j;

        for (i = j = 0; s1[i] != '\0'; ++i)
        {
            if (s1[j++] == s2[k])
            {
                return i;
            }
        }
    }

    return result;
}

main()
{
    char s1[] = "This is a test that is easy.";
    
    char t1[] = "y.";
    char t2[] = "zg";

    int r1 = any(s1, t1);
    int r2 = any(s1, t2);

    printf("%d %d\n", r1, r2);

    return 0;
}