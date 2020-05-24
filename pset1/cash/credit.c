#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Function prototype
int doubleSecond(int n);

int main(void)
{
    long card;

    // Get the card number
    card = get_long("Enter Card Number: ");


    // Print out values
    // printf("%i the double\n", doubleSecond(card));

    // Initialize variables
    int count = 0;
    long number = card;
    int sum = 0;

    // The magic
    while (number != 0)
    {
        // Unpack digits
        int digit = number % 10;

        // Update count
        count++;

        // Digits left
        number /= 10;

        // The sum
        if (count % 2 == 0) sum += doubleSecond(digit);
        else sum += digit;
    }

    // Valid or Invalid
    if (sum % 10 != 0)
    {
        printf("%s\n", "INVALID");
        return 1;
    }
    else
    {
      if (count == 15)
      {
          printf("%s\n", "AMEX");
      }
      else
      {
          // Try checking if VISA
          int digit = card / (pow(10, (count - 1)));

          if (digit == 4)
          {
              printf("%s\n", "VISA");
              return 0;
          }

          // Two digits for mastercard
          int digits = card / (pow(10, (count - 2)));

          if (digits == 51 || digits == 52 || digits == 53 || digits == 54 || digits == 55)
          {
              printf("%s\n", "MASTERCARD");
              return 0;
          }

          printf("INVALID\n");
      }
    }


}

int doubleSecond(int n)
{
    // Returns the sum of every second digit
    int sum = n * 2;
    if (sum > 10) sum = 1 + sum % 10;
    return sum;
}
