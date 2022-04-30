#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//              A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(int argc, string argv[])
{

    // Get Input
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");


    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print what is the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins\n");
    }
    else
    {
        printf("Tie!\n");
    }

return 0;
}

int compute_score(string word)
{
    int sum = 0;
    int index = 0;
    int res = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (islower(word[i]))
        {
            index = (word[i] - 97);
            res += POINTS[index];
        }
        else if (isupper(word[i]))
        {
            index = (word[i] - 65);
            res += POINTS[index];
        }
        else
        {
            res += 0;
        }
    }
return res;
}