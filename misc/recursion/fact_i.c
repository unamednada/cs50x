#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num = get_int("Factorial of: ");
    int result = num;

    for (int i = num - 1; i > 0; i--)
    {
        result *= i;
    }

    printf("%i! = %i\n", num, result);
}