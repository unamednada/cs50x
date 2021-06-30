#include <cs50.h>
#include <stdio.h>

int fact(int n);

int main(void)
{
    int num = get_int("Factorial of: ");

    int result = fact(num);

    printf("%i! = %i\n", num, result);
}

int fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}