#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    // Initialize key variable
    string key;

    if (argc == 2)
    {
        // Great
        // Does the key have 26 characters?
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 letters.\n");
            return 1;
        }
        else
        {
            // Extract the key
            key = argv[1];
        }
    }
    else
    {
        printf("Usage: substitution key\n");
        return 1;
    }

    // If we have gotten here, then it is all good.
    // Get the plaintext
    string text = get_string("Plaintext: ");


    // Encode
    printf("Ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++)
    {
        // One character at a time.
        char c = text[i];

        if (isalpha(c))
        {
            if (isupper(c))
            {
                // Get index of current letter in key, using it's ASCII code
                // 'A' = 65
                int index = c - 65;
                // Encode using the substitute from the key
                printf("%c", toupper(key[index]));
            }
            else
            {
                // Lowercase
                // 'a' = 97
                int index = c - 97;
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            // Non-alphabet
            printf("%c", c);
        }
    }

    // Newline
    printf("\n");
    return 0;
}