#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// string.h to use strlen
// ctype.h to use toupper and isalpha

// Calculate the pontuation of a word
int compute_score(char *word);

int main(void)
{
    // Get first word
    string word1 = get_string("Player 1: ");

    // Get second word
    string word2 = get_string("Player 2: ");

    // Calculate both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine who is the winner or if it was a tie
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int compute_score(char *word)
{
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            // Make every character uppercase
            char upper = toupper(word[i]);
            // Calculate the i of each letter
            score += points[upper - 'A'];
        }
    }

    return score;
}
