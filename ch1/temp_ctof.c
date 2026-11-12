#include <stdio.h>

main()
{
    float fahrenheit, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;

    printf("Celsius   Fahrenheit\n");

    while (celsius <= upper)
    {
        fahrenheit = (9.0 / 5.0 * celsius) + 32.0;

        printf("%7.0f %12.1f\n", celsius, fahrenheit);

        celsius = celsius + step;
    }
}