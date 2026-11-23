#include <stdio.h>

void
strcatx(char *s, char *t)
{
    for ( ; *s != '\0'; s++);
    while (*s++ = *t++);
}

main()
{
    char s1[] = "This is a ";
    char t1[] = "test.";

    strcatx(s1, t1);

    printf("%s\n", s1);

    return 0;
}