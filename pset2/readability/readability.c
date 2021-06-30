#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Declare useful functions for counting letters, words and sentences
int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    // Get input from user
    string text = get_string("Text: ");

    // Declare and find number of letters, words and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate the values of L and S for the Coleman-Liau index
    float L = (letters * 1.0 / words) * 100;
    float S = (sentences * 1.0 / words) * 100;

    // Calculate the index and round it to obtain grade level
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int grade = round(index);

    // Check if grade is too low or too high and print result
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade >= 1)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

// Definition of function that counts letters
int count_letters(string s)
{
    // Initialize counter
    int count = 0;

    // Iterate over each index in the given text
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        // Convert to upper case and check if it's in the alphabet
        char letter = toupper(s[i]);
        if (letter >= 'A' && letter <= 'Z')
        {
            count ++;
        }
    }
    return count;
}

// Definition of function that counts words
int count_words(string s)
{
    int count = 1;

    // Iterate over each index and check for spaces to find words
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

// Definition of function to count sentences
int count_sentences(string s)
{
    int count = 0;

    // Iterate over each index and check for punctuation to find sentences
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            count ++;
        }
    }
    return count;
}