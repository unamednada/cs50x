#include <stdio.h>
#include <cs50.h>

//LESS

int main(void)
{
    //Declaration of useful variables
    int height, points;

    //Asking user for input
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //Main for loop responsible for the lines
    for (int i = 0; i < height; i++)
    {
        //Inner while loop responsible for the spaces
        points = i + 1;
        while (points < height)
        {
            printf(" ");
            points++;
        }

        //Inner for loop responsible for the hashes
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}