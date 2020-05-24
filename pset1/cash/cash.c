#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;

    // Get the change
    do
    {
        change = get_float("How much change do you need? ");
    } while (change < 0.00 );

    int dollars = round(change * 100);

    // Initialize variables
    int count = 0;
    int change_left = dollars;

    while (change_left != 0)
    {
        if (change_left > 25)
        {
            count += change_left / 25;
            change_left %= 25;
        }
        else if (change_left > 10)
        {
            count += change_left / 10;
            change_left %= 10;
        }
        else if (change_left > 5)
        {
            count += change_left / 5;
            change_left %= 5;
        }
        else
        {
            count += change_left / 1;
            change_left %= 1;
        }
    }

    // Return the number
    printf("%i\n", count);
    return 0;
}