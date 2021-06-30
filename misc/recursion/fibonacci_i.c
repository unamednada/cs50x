#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int fibonacci[10];

    for (int i = 0; i < 10; i++)
    {
        if (i <= 1)
            fibonacci[i] = i;
        else
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    for (int i = 0; i < 10; i++)
        printf("%i ", fibonacci[i]);

    printf("\n");
}