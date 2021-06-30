#include <stdio.h>
#include <cs50.h>
//Library containing round
#include <math.h>

int main(void)
{
    //Declaring important variables
    float dollars;
    int coins = 0;

    //Asking input from user
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    //Converting input to int
    int cents = round(dollars * 100);

    //Calculating coins
    while (cents != 0)
    {
        if (cents >= 25)
        {
            coins += cents / 25;
            cents = cents % 25;
        }
        else if (cents >= 10)
        {
            coins += cents / 10;
            cents = cents % 10;
        }
        else if (cents >= 5)
        {
            coins += cents / 5;
            cents = cents % 5;
        }
        else
        {
            coins += cents;
            cents = 0;
        }
    }

    printf("%i\n", coins);
}