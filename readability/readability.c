#include <cs50.h>  // To use get_string
#include <ctype.h> // To use isalnum and isspace
#include <stdio.h>

float letters_per_100_words(int letters, int words);
float sentences_per_100_words(int sentences, int words);
int coleman_liau_index(float L, float S);

int main(void)
{
    string text = get_string("Text: ");

    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalnum(text[i])) // If character is a letter or a number
        {
            letters++;
        }
        else if (isspace(text[i])) // If character is a blank space
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' ||
                 text[i] == '?') // If it is a character that separates sentences
        {
            sentences++;
        }
    }

    if (letters > 0 || sentences > 0)
    {
        words++;
    }

    // Calculate L and S
    float L = letters_per_100_words(letters, words);
    float S = sentences_per_100_words(sentences, words);

    int index = coleman_liau_index(L, S);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}

// Calculate L
float letters_per_100_words(int letters, int words)
{
    return (float) letters / words * 100;
}

// Calculate S
float sentences_per_100_words(int sentences, int words)
{
    return (float) sentences / words * 100;
}

// Calculate Coleman-Liau index of a text
int coleman_liau_index(float L, float S)
{
    return (int) (0.0588 * L - 0.296 * S - 15.8 + 0.5); // Get the closest int
}
