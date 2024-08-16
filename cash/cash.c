#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int QUARTER = 25;
    const int DIME = 10;
    const int NICKEL = 5;
    const int PENNY = 1;
    int amount;
    int coins = 0;

    while (true)
    {
        amount = get_int("Change owed: ");

        if (amount > 0)
        {
            break;
        }
    }

    coins += amount / QUARTER;
    amount %= QUARTER;

    coins += amount / DIME;
    amount %= DIME;

    coins += amount / NICKEL;
    amount %= NICKEL;

    coins += amount;

    printf("%d\n", coins);

    return 0;
}
