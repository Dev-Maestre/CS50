#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Functions
bool _validKey (string s);

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("Usage: ./substitution KEY\n");
        return 1;
    }

    if (!_validKey(argv[1]))
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    string s = get_string("Plaintext: "); // Get plaintext
    printf("Ciphertext: ");

    for (int i = 0, len = strlen(s); i < len; i++)
    {
      if (!isdigit(s[i]) && isupper(s[i]))  // Check the uppercase character
      {
          int upper = (s[i] - 65);
          printf("%c", toupper(argv[1][upper]));
      }
      else if (!isdigit(s[i]) && islower(s[i])) // Check the lowecase character
      {
          int lower = (s[i] - 97);
          printf("%c", tolower(argv[1][lower]));
      }
      else // If aren't character, print it is
      {
          printf("%c", s[i]);
      }
    }./SU

printf("\n");
}

bool _validKey (string s)
{

    int len = strlen(s); // Picking the lenght of the key

    // Check 26 characters
    if (len != 26)
    {
       return false;
    }

    int freq[26] = { 0 };
    for (int i = 0; i < len; i++)
    {
        // Check key have a digit
        if (isdigit(s[i]))
        {
            return false;
        }

        // Check same letters
        int index = toupper(s[i] - 'A');
        if (freq[index] > 0)
        {
            return false;
        }
    freq[index]++;
    }

    return true;
}