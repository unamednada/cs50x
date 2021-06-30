#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int count = 0;
        for (int i = 0, length = strlen(argv[1]); i < length; i++)
        {
            if isalpha(argv[1][i])
            {
                count ++;
            }
            break;
        }
        if (count == 0)
        {
            int key = atoi(argv[1]);

            string p = get_string("plaintext: ");

            for (int i = 0, length = strlen(p); i < length; i++)
            {
                if (isalpha(p[i]))
                {
                    if (islower(p[i]))
                    {
                        char letter = toupper(p[i]);
                        int index = letter - 65;
                        char new_index = (index + key) % 26;
                        char new_letter = tolower(new_index + 65);
                        p[i] = new_letter;
                    }
                    else
                    {
                        char letter = p[i];
                        int index = letter - 65;
                        char new_index = (index + key) % 26;
                        char new_letter = new_index + 65;
                        p[i] = new_letter;
                    }
                }
            }
            printf("ciphertext: %s\n", p);
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
        }
    }
}
