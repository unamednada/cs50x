#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int array[] = {325, 2, -5, 67, 8, 19, 1000000000};

    for (int i = 0; i < 8; i++)
    {
        int min = array[i];

        for (int j = i; j < 8; j++)
        {
            if (array[i] > array[j])
            {
                min = array[j];
                array[j] = array[i];
                array[i] = min;
            }
        }

    }

    for (int i = 0; i < 8; i++)
    {
        printf("%i ", array[i]);
    }
}