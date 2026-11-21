#include <stdio.h>
#include <stdlib.h>
#include "../util.c"

#define MAXOP       100
#define NUMBER      '0'

int getop(char []);

void push(double);
double pop(void);
double peek(void);

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

#define MAXVAL  100

int stack_index = 0;
double val[MAXVAL];

void 
push(double f)
{
    if (stack_index < MAXVAL)
    {
        val[stack_index++] = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

double 
pop(void)
{
    if (stack_index > 0)
    {
        return val[--stack_index];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double
peek(void)
{
    if (stack_index > 0)
    {
        return val[stack_index];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getchx(void);
void putchx(int);

int
getop(char s[])
{
    int i, c;

    while ((s[0] = c = getchx()) == ' ' || c == '\t');

    s[1] = '\0';



    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }

    i = 0;

    if (c == '-' || isdigit(c))
    {
        while (isdigit(s[++i] = c = getchx()));
    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = getchx()));
    }

    s[i] = '\0';

    if (c != EOF)
    {
        putchx(c);
    }

    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int
getchx(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void
putchx(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("putch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
