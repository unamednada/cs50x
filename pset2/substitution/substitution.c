#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Declare useful functions
bool isvalidkey(string s);
char substitute(char p, string key);

int main(int argc, string argv[])
{
    // Check if there is only one argument and print message to user
    if (argc != 2)
    {
        printf("Usage ./substitution key\n");
        return 1;
    }

    string key = (string) argv[1];

    // Use function to check if key has 26 unique letters and print message to user
    if (isvalidkey(key) == false)
    {
        printf("Key must contain 26 unique letters.\n");
        return 1;
    }

    // Ask for user input
    string p = get_string("plaintext: ");

    // Iterate over each index
    for (int i = 0, l = strlen(p); i < l; i++)
    {
        // Check if char in that position is a letter
        char c = p[i];
        if (isalpha(c))
        {
            // If it is a letter, use the substitute function to encript the letter
            p[i] = substitute(c, key);
        }
    }

    // Print the result to user
    printf("ciphertext: %s\n", p);
    return 0;
}

// Declare function to check if key has 26 unique letters and sets it to uppercase
bool isvalidkey(string s)
{
    // Getting length of the key
    int l = strlen(s);

    // If the length is different than 26, the key is invalid
    if (l != 26)
    {
        return false;
    }

    //Iterate over each char in the key
    for (int i = 0; i < l; i++)
    {
        // Initialize counter to check for duplicates
        int count = 0;

        // Check if the character is a letter
        if (isalpha(s[i]) == false)
        {
            return false;
        }

        //Iterate over the key and check for duplicates, increase counter
        for (int j = 0; j < l; j++)
        {
            if (s[i] == s[j])
            {
                count ++;
            }
        }

        //Check if there are more than 1 ocurrence of that letter in key
        if (count > 1)
        {
            return false;
        }

        // Set letter to uppercase
        s[i] = toupper(s[i]);
    }
    return true;
}

// Declare function that encripts each letter
char substitute(char p, string key)
{
    // Set letter to uppercase to facilitate
    char pup = toupper(p);

    // Get corresponding index in the key
    int index = (int)(pup - 65);

    // Check if original letter was lower and return the lower version of the encripted letter
    if (islower(p))
    {
        return (char) tolower(key[index]);
    }

    // Return the encripted letter
    return (char) key[index];
}