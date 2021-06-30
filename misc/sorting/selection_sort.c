#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int array[] = {5, 2, 1, 3, 6, 4};

    for (int j = 0; j < 6; j++)
    {
        int min = array[j];
        int index = j;

        for (int i = j; i < 6; i++)
        {
            if (array[i] < min)
            {
                min = array[i];
                index = i;
            }
        }

        array[index] = array[j];
        array[j] = min;
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%i ", array[i]);
    }
}