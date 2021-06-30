#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int array[] = {-12, 23, 300, 400, 512, 6037, 7000, 8000, 9112, 10000, 110000, 120000, 1300000, 14000000, 15222222};

    int start = 0;
    int end = 14;
    int num = 1000;

    do
    {
        int index = floor((start + end) / 2);
        if (array[index] < num)
        {
            start = index + 1;
        }
        else if (array[index] > num)
        {
            end = index - 1;
        }
        else
        {
            printf("Found! Position: %i\n", index);
            return 0;
        }
    }
    while (end >= start);

    printf("Not found!\n");
    return 1;
}