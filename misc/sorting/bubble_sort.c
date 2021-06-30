#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int array[] = {3, 4, 6, 7, 5, 2, 8, 1};
    int swap;

    do
    {
        swap = 0;
        for (int i = 0; i < 7; i++)
        {
            if (array[i + 1] < array[i])
            {
                int min = array[i + 1];
                array[i + 1] = array[i];
                array[i] = min;
                swap++;
            }
        }
    }
    while (swap != 0);

    for (int j = 0; j < 8; j++)
    {
        printf("%i ", array[j]);
    }
}