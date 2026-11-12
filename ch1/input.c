#include <stdio.h>

main()
{
    printf("%d\n", EOF);

    int result = (getchar() != EOF);

    printf("%d\n", result);
}