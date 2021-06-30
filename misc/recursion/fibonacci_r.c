#include <cs50.h>
#include <stdio.h>

int fibonacci_element(int index);

int main(void)
{
    int length = get_int("Fibonacci of length: ");
    int result[length];

    for (int i = 0; i < length; i++)
        result[i] = fibonacci_element(i);

    for (int i = 0; i < length; i++)
        printf("%i ", result[i]);

    printf("\n");
}

int fibonacci_element(int index)
{
    if (index <= 1)
        return index;
    else
        return fibonacci_element(index -1) + fibonacci_element(index - 2);
}