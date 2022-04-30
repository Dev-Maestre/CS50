#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    string key = argv[1];

    // Check that input of user has a correct key
    if (argc != 2)
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }

    // Check that input of user is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./ceasar key\n");
            return 1;
        }
    }

    // Doing the cyphertext
    if (argc == 2)
    {
        // Convert key to int with the stdlib.h
        int k = atoi(key);

        // Getting the plaintext
        string p = get_string("Plaintext: ");

        // Print to user the cyphertext
        printf("Cyphertext: ");
        for (int i = 0, n = strlen(p); i < n; i++)
        {
            if(p[i] >= 'a' && p[i] <= 'z')
            {
                printf("%c", (((p[i] - 97) + k) % 26) + 97);
            }
            else
            if (p[i] >= 'A' && p[i] <= 'Z')
            {
                printf("%c", (((p[i] - 65) + k) % 26) + 65);
            }
            else
            {
                printf("%c", p[i]);
            }
        }
    }

    printf("\n");
}