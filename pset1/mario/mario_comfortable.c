#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    do
    {
       n = get_int("How high do you want the table? ");
    }
    while (n < 1 || n > 8);

    for (int i = 1; i <= n; i++)
    {
        // The spaces
        for (int k = 0; k < n - i; k++)
        {
            printf(" ");
        }

        // The '#'
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        // The two spaces
        printf("  ");

        // The regular pyramid
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }

        printf("\n");
    }
    return 0;
}