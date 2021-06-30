#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int num = atoi(argv[1]);
    int steps = 0;

    while (num > 0)
    {
        if (num == 1)
        {
            printf("%i steps\n", steps);
            return 0;
        }
        else if (num % 2 == 0)
        {
            num /= 2;
            steps++;
        }
        else
        {
            num = (3 * num) + 1;
            steps++;
        }
    }

    printf("%i steps\n", steps);
    return 0;
}