#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool isnumstr(string s);
char caesarchar(char c, int k);

int main(int argc, string argv[])
{
    if (argc != 2 || isnumstr(argv[1]) == false)
    {
        printf("Usage ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string p = get_string("plaintext: ");

    for (int i = 0, l = strlen(p); i < l; i++)
    {
        if (isalpha(p[i]))
        {
            char c = p[i];
            p[i] = caesarchar(c, key);
        }
    }
    printf("ciphertext: %s", p);
    return 0;
}

bool isnumstr(string s)
{
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if (isdigit(s[i]) == false)
        {
            return false;
        }
    }
    return true;
}

char caesarchar(char c, int k)
{
    if (islower(c))
    {
        c = (int) toupper(c) - 65;
        return (char) tolower(((c + k) % 26) + 65);
    }
    c = (int) c - 65;
    return (char)((c + k) % 26) + 65;
}