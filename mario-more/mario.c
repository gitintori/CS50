#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    while (true)
    {
        n = get_int("Height (between 1 and 8): ");

        if (n >= 1 && n <= 8)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
