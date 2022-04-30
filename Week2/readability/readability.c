#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main (void)
{
    int letter = 0, words = 0, phrases = 0;
    string text = get_string ("TEXT: ");

    for (int i = 0, n = strlen(text); i < n; i++) // Or (int = 0; text[i] != '\0' ; i++)
    {
        // Count number of letters
        if (text[i] >= 'a' && text[i] <='z')
        {
            letter++;
        }
        else
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letter++;
        }

        // Count number of words
        if (text[i] == ' ')
        {
            words++;
        }

        // Count number of phrases
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            phrases++;
        }

    }

    // Calculing the forms
    words += 1;
    float index = 0, l = 0, s = 0;
    l = letter*(100/(float)words);
    s = phrases*(100/(float)words);

    index = 0.0588 * l - 0.296 * s -15.8;

    // Prompt to user the informations
    printf("TEXTO: %s\n", text);
    printf("Letras: %i\n", letter);
    printf("Frase: %i\n", phrases);
    printf("Palavras: %i\n", words);
    printf("Media letra: %.2f\n", l);
    printf("Media frase: %.2f\n", s);

    // Prompt to user the result
    if (index <= 1)
    {
        printf("Before grade 1\n");
    }
    else
    if (index > 1 && index < 16)
    {
        printf("Grade: %.0f\n", round(index));
    }
    else
    {
        printf("Grade: 16+");
    }
}