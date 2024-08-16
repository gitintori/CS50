#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> // To use atoi to receive a string as an argument

char cipher_letter(char letter, int key)
{
    if (isalpha(letter)) // If it is a letter
    {
        char base = isupper(letter) ? 'A' : 'a'; // Check if uppercase or lower case
        letter = base + (letter - base + key) % 26;
    }
    // If not a letter, return the original character (for example: ! is still !)
    return letter;
}

int main(int argc, string argv[])
{
    // Verifies if it is a valid key
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Verifies if key has only digits
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Key must be a number.\n");
            return 1;
        }
    }

    // Takes the key on the command line (string) in an int
    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    // Iterate every character
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        // Cipher each letter
        char ciphered_letter = cipher_letter(plaintext[i], key);
        printf("%c", ciphered_letter);
    }

    printf("\n");

    return 0;
}
