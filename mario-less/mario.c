#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for positive integer
    int n;

    while (true)
    {
        n = get_int("Height: ");

        if (n > 0)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        // To justify it right:
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Print hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
