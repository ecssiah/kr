#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP       100

main()
{
    int type;
    double op_right;
    double result = 0.0;

    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op_right = pop();
            push(pop() - op_right);
            break;
        case '/':
            op_right = pop();

            if (op_right != 0.0)
            {
                push(pop() / op_right);
            }
            else
            {
                printf("error: zero divisor\n");
            }
            
            break;
        case '%':
            op_right = pop();

            if (op_right != 0.0)
            {
                push((int)pop() % (int)op_right);
            }
            else
            {
                printf("error: zero divisor\n");
            }

            break;
        case '\n':
            result = pop();
            printf("\t%.8g\n", result);
            break;
        case '^':
            push(result);
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}
