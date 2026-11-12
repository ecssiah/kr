#include <stdio.h>

#define FOLD_COLUMN     12
#define MAX_LINE_LENGTH 1000

int getline(char line[], int max_length);
void fold(char line[], int col);

main()
{
    int length;

    char line[MAX_LINE_LENGTH];

    while ((length = getline(line, MAX_LINE_LENGTH)) != EOF)
    {
        if (length < FOLD_COLUMN)
        {
            printf("%s", line);
        }
        else
        {
            fold(line, FOLD_COLUMN);
        }
    }

    return 0;
}

int getline(char line[], int max_length)
{
    int c;
    int i = 0;

    while ((c = getchar()) != EOF) 
    {
        if (c == '\n' || i >= max_length - 1)
        {
            line[i + 0] = '\n';
            line[i + 1] = '\0';

            return i;
        }
        else if (i > max_length - 2)
        {
            line[i + 0] = '\n';
            line[i + 1] = '\0';

            return max_length;
        }
        else
        {
            line[i] = c;
            ++i;
        }
    }

    return EOF;
}

void fold(char line[], int col)
{
    int start_index = 0;
    int current_index = 0;

    while (1)
    {
        if (line[current_index] == '\0')
        {
            int j;
            for (j = start_index; j < current_index; ++j)
            {
                putchar(line[j]);
            }

            break;
        }
        else if (current_index - start_index + 1 == col)
        {
            int last_break_index = current_index;

            while (
                last_break_index > start_index && 
                line[last_break_index] != ' ' && 
                line[last_break_index] != '\t'
            )
            {
                --last_break_index;
            }

            if (last_break_index == start_index)
            {
                last_break_index = current_index;
            }

            int j;
            for (j = start_index; j <= last_break_index; ++j)
            {
                putchar(line[j]);
            }

            putchar('\n');

            while (line[j] == ' ' || line[j] == '\t')
            {
                ++j;
            }

            start_index = current_index = j;
        }
        else
        {
            ++current_index;
        }
    }
}
