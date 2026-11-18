#include <stdio.h>

void
itob(int n, char s[], int b)
{
    int i, sign;

    switch (b)
    {
        case 2:

            break;
        case 8:

            break;
        case 10:

            break;
        case 16:

            break;
        default:
            break;
    }
}

main()
{
    int n1 = 1024;

    char s1[100];
    char s2[100];
    char s3[100];
    char s4[100];

    itob(n1, s1, 2);
    itob(n1, s2, 2);
    itob(n1, s3, 2);
    itob(n1, s4, 2);

    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);
    printf("%s\n", s4);

    return 0;
}