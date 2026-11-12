#include <stdio.h>

main()
{
    

    int i, j;

    char test_string[] = "We better watch /* out */ for these!";

    for (j = 0; j < 10; ++j)
    {
        for (i = j; i < 10; ++i)
        {
            
            printf("(%d %d)\n", i, j);

            char test_char = '"';

            putchar(test_char);
        }
    }

    return 0;
}
