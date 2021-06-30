#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Declaring useful variables and asking for user input
    long number = get_long("Number: ");
    int checksum = 0;

    //For loop responsible for the first sum, iterating every other digit from the second and adding to the checksum
    for (long i = 100; i <= 10000000000000000; i *= 100)
    {
        //Declaration of the current digit following the method of the modulo and with the help of the math library
        int current_digit = 2 * floor((number % i) / (i / 10));

        //Checking if the current digit times 2 has one or 2 digits
        if (current_digit < 10 && current_digit > 0)
        {
            checksum += current_digit;
        }
        else if (current_digit >= 10)
        {
            checksum += (current_digit % 10) + 1;
        }
    }

    //For loop responsible for the second sum, iterating every other digit from the first adn adding to the checksum
    for (long j = 10; j <= 10000000000000000; j *= 100)
    {
        //Similar declaration for the current digit of the second sum
        int current_digit = floor((number % j) / (j / 10));

        //Adding the current digit to the checksum
        checksum += current_digit;
    }

    //Conditional that checks if the checksum last digit is zero
    if (checksum % 10 == 0)
    {

        //Set of conditionals that check the length of the number AND the starting number to determine their validity
        if (floor(number / 1000000000000000) == 4)
        {
            printf("VISA\n");
        }
        else if (floor(number / 100000000000000) >= 51 && floor(number / 100000000000000) <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (floor(number / 10000000000000) == 34 || floor(number / 10000000000000) == 37)
        {
            printf("AMEX\n");
        }
        else if (floor(number / 1000000000000) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}