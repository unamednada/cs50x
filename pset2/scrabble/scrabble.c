#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Check which score is higher and print the result
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

// Function definition to compute score
int compute_score(string word)
{
    // Declaration of initial score
    int score = 0;

    // Iterate over each position in word
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        // Convert word to uppercase
        char letter = toupper(word[i]);

        // Check if current letter is valid or not
        if (letter > 'Z' || letter < 'A')
        {
            score += 0;
        }
        else
        {
            // Use the ASCII chart to convert the current letter to the corresponding index in POINTS
            score += POINTS[letter - 65];
        }

    }
    return score;
}
