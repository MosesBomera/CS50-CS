#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int key = 0;

    // Check program arguments
    if (argc == 2)
    {
        // Get argument length
        int n = strlen(argv[1]);

        // Converts anything that starts with a digit
        int result = atoi(argv[1]);

        for (int i = 0; i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ceaser key\n");
                return 1;
            }
        }

        if (result == 0 )
        {
            printf("Usage: ceaser key\n");
        }
        else
        {
            // Assign a valid integer number, > 0
            if (result > 0)
            {
                key = result;
            }
            else
            {
                printf("Usage: ceaser key\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ceaser key\n");
        return 1;
    }

    // If we make it here, then it is all good.
    string plaintext = get_string("Plaintext: ");

    // Good design?
    printf("Ciphertext: ");

    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        // Represent A as 0, through to Z as 25.
        char c = plaintext[i];


        // Only encode the alphabet

        if (isalpha(c))
        {
            if (isupper(c))
            {
                printf("%c", (((c - 65) + key) % 26 + 65 ));
            }
            else
            {
                printf("%c", (((c - 97) + key) % 26 + 97));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
    return 0;
}