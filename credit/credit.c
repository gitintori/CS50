#include <cs50.h>
#include <stdio.h>

bool is_valid_credit_card(long long card_number);
void check_card_type(long long card_number);

int main(void)
{
    long long card_number;

    while (true)
    {
        card_number = get_long("Number: ");

        int length = 0;
        long long typedNumber = card_number;
        while (typedNumber > 0)
        {
            typedNumber /= 10;
            length++;
        }

        if (length >= 13 && length <= 16)
        {
            break;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }

    if (is_valid_credit_card(card_number))
    {
        check_card_type(card_number);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

bool is_valid_credit_card(long long card_number)
{
    int sum = 0;
    int count = 0;

    while (card_number > 0)
    {
        int digit = card_number % 10;
        card_number /= 10;

        if (count % 2 != 0)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit = (digit % 10) + 1;
            }
        }

        sum += digit;
        count++;
    }
    return (sum % 10 == 0);
}

void check_card_type(long long card_number)
{
    long long typedNumber = card_number;
    while (typedNumber >= 100)
    {
        typedNumber /= 10;
    }

    int first_two_digits = typedNumber;

    int length = 0;
    typedNumber = card_number;
    while (typedNumber > 0)
    {
        typedNumber /= 10;
        length++;
    }

    if ((first_two_digits == 34 || first_two_digits == 37) && length == 15)
    {
        printf("AMEX\n");
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55 && length == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((first_two_digits / 10 == 4) && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
